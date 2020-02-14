#include "Graph.h"

int main(void)
{
    extern bool visited[];
    graph_t G = CreateGraph();

    // 从结点0开始，6个结点BFS无问题，初步完成，待重构
    Link(G, 0, 1, 1);
    Link(G, 1, 2, 1);
    Link(G, 0, 3, 1);
    Link(G, 0, 4, 1);
    Link(G, 4, 5, 1);

    printf("BFS:\n");
    BFS(G, 0);
    for (int i = 0; i < VERTEX_NUMBER; ++i)
    {
        visited[i] = false;
    }
    printf("DFS:\n");
    DFS(G, 0);

    getchar();
    return 0;
}
