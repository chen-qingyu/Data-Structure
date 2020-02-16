#include "Graph.h"

int main(void)
{
    extern bool visited[];
    graph_t G = CreateGraph();

    Link(G, 0, 1, 1);
    Link(G, 1, 2, 1);
    Link(G, 0, 3, 1);
    Link(G, 3, 6, 1);
    Link(G, 4, 5, 1);
    Link(G, 5, 6, 1);
    Link(G, 6, 7, 1);
    Link(G, 7, 8, 1);
    Link(G, 8, 9, 1);

    printf("BFS:\n");
    CleanFlag();
    BFS(G, 0);

    printf("DFS:\n");
    CleanFlag();
    DFS(G, 0);

    getchar();
    return 0;
}
