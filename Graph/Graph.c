#include "Graph.h"

bool visited[VERTEX_NUMBER] = {false};

graph_t CreateGraph(void)
{
    graph_t G = (graph_t)malloc(sizeof(struct graph));
    if (G == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    vertex_t V1, V2;

    G->vertexNum = VERTEX_NUMBER;
    G->edgeNum = 0;

    for (V1 = 0; V1 < G->vertexNum; V1++)
    {
        for (V2 = 0; V2 < G->vertexNum; V2++)
        {
            G->matrix[V1][V2] = 0;
        }
    }

    return G;
}

void Link(graph_t G, vertex_t V1, vertex_t V2, weight_t weight)
{
    G->matrix[V1][V2] = weight;
    G->matrix[V2][V1] = weight;
}

bool IsAdjacent(graph_t G, vertex_t V1, vertex_t V2)
{
    return G->matrix[V1][V2] != 0 ? true : false;
}

void Visit(vertex_t V)
{
    printf("Visiting vertex: %d\n", V);
}

void BFS(graph_t G, vertex_t startV)
{
    queue_t Q = CreateQueue();
    vertex_t V1, V2;

    Visit(startV);
    visited[startV] = true;
    AddQ(Q, startV);

    while (!IsEmpty(Q))
    {
        V1 = DeleteQ(Q);
        for (V2 = 0; V2 < G->vertexNum; V2++)
        {
            if (!visited[V2] && IsAdjacent(G, V1, V2))
            {
                Visit(V2);
                visited[V2] = true;
                AddQ(Q, V2);
            }
        }
    }
}

void DFS(graph_t G, vertex_t startV)
{
    vertex_t V1, V2;

    Visit(startV);
    visited[startV] = true;

    for (V2 = 0; V2 < G->vertexNum; V2++)
    {
        if (IsAdjacent(G, startV, V2) && !visited[V2])
        {
            DFS(G, V2);
        }
    }
}
