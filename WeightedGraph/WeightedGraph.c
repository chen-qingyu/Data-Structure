#include "WeightedGraph.h"

bool visited[VERTEX_NUMBER] = {false};

/*******************************
Helper functions implementation.
*******************************/

static void CleanVisitedFlag(void)
{
    for (vertex_t i = 0; i < VERTEX_NUMBER; i++)
    {
        visited[i] = false;
    }
}

static void _DFS(graph_t G, vertex_t startV, void (*pVisit)(vertex_t V))
{
    vertex_t V1;

    pVisit(startV);
    visited[startV] = true;

    for (V1 = 0; V1 < G->vertexNum; V1++)
    {
        if (IsAdjacent(G, startV, V1) && !visited[V1])
        {
            _DFS(G, V1, pVisit);
        }
    }
}

static vertex_t FindMinDist(const graph_t G, edge_t dist[], bool collected[])
{
    vertex_t MinV, V;
    int minDist = NO_PATH;

    for (V = 0; V < G->vertexNum; V++)
    {
        if (collected[V] == false && dist[V] < minDist)
        {
            minDist = dist[V];
            MinV = V;
        }
    }

    return (minDist < NO_PATH) ? MinV : ERROR;
}

/*******************************
Interface functions implementation.
*******************************/

graph_t CreateGraph(void)
{
    graph_t G = (graph_t)malloc(sizeof(struct graph));
    if (G == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    G->vertexNum = VERTEX_NUMBER;
    G->edgeNum = 0;

    for (vertex_t V1 = 0; V1 < G->vertexNum; V1++)
    {
        for (vertex_t V2 = 0; V2 < G->vertexNum; V2++)
        {
            G->matrix[V1][V2] = NO_PATH;
        }
    }

    return G;
}

void DestroyGraph(graph_t G)
{
    if (G)
    {
        free(G);
        G = NULL;
    }
}

void Link(graph_t G, vertex_t V1, vertex_t V2, edge_t E)
{
    G->matrix[V1][V2] = E;
#ifdef UNDIRECTED
    G->matrix[V2][V1] = E;
#endif
}

bool IsAdjacent(const graph_t G, vertex_t V1, vertex_t V2)
{
    return G->matrix[V1][V2] != NO_PATH ? true : false;
}

void DFS(graph_t G, vertex_t startV, void (*pVisit)(vertex_t V))
{
    CleanVisitedFlag();
    _DFS(G, startV, pVisit);
}

void BFS(graph_t G, vertex_t startV, void (*pVisit)(vertex_t V))
{
    CleanVisitedFlag();
    queue_t Q = CreateQueue();
    vertex_t V1, V2;

    pVisit(startV);
    visited[startV] = true;
    Enqueue(Q, startV);

    while (!IsEmpty(Q))
    {
        V1 = Dequeue(Q);
        for (V2 = 0; V2 < G->vertexNum; V2++)
        {
            if (!visited[V2] && IsAdjacent(G, V1, V2))
            {
                pVisit(V2);
                visited[V2] = true;
                Enqueue(Q, V2);
            }
        }
    }
    DestroyQueue(Q);
}

bool Dijkstra(const graph_t G, edge_t dist[], vertex_t path[], vertex_t startV)
{
    bool collected[VERTEX_NUMBER] = {false};
    vertex_t V1, V2;

    for (V1 = 0; V1 < G->vertexNum; V1++)
    {
        dist[V1] = G->matrix[startV][V1];
        if (dist[V1] < NO_PATH)
        {
            path[V1] = startV;
        }
        else
        {
            path[V1] = -1;
        }
    }

    dist[startV] = 0;
    collected[startV] = true;

    while (1)
    {
        V1 = FindMinDist(G, dist, collected);
        if (V1 == ERROR)
        {
            break;
        }
        collected[V1] = true;
        for (V2 = 0; V2 < G->vertexNum; V2++)
        {
            if (collected[V2] == false && G->matrix[V1][V2] < NO_PATH)
            {
                if (G->matrix[V1][V2] < 0)
                {
                    return false;
                }
                if (dist[V1] + G->matrix[V1][V2] < dist[V2])
                {
                    dist[V2] = dist[V1] + G->matrix[V1][V2];
                    path[V2] = V1;
                }
            }
        }
    }

    return true;
}

bool Floyd(const graph_t G, edge_t dist[][VERTEX_NUMBER], vertex_t path[][VERTEX_NUMBER])
{
    vertex_t i, j, k;

    for (i = 0; i < G->vertexNum; i++)
    {
        for (j = 0; j < G->vertexNum; j++)
        {
            dist[i][j] = G->matrix[i][j];
            path[i][j] = -1;
        }
    }

    for (k = 0; k < G->vertexNum; k++)
    {
        for (i = 0; i < G->vertexNum; i++)
        {
            for (j = 0; j < G->vertexNum; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    if (i == j && dist[i][j] < 0)
                    {
                        return false;
                    }
                    path[i][j] = k;
                }
            }
        }
    }

    return true;
}
