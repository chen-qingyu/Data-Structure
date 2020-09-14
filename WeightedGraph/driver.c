#include "WeightedGraph.h"

int main(void)
{
    extern bool visited[];
    graph_t G = CreateGraph();

    Link(G, 0, 1, 2);
    Link(G, 0, 3, 1);
    Link(G, 1, 4, 10);
    Link(G, 1, 3, 3);
    Link(G, 2, 0, 4);
    Link(G, 2, 5, 5);
    Link(G, 3, 2, 2);
    Link(G, 3, 4, 2);
    Link(G, 3, 5, 8);
    Link(G, 3, 6, 4);
    Link(G, 6, 5, 1);

    printf("      +--+   2    +--+      \n");
    printf("      |V0|------->|V1|      \n");
    printf("      +--+        +--+      \n");
    printf("   +--^  | 1    3 |  |  10  \n");
    printf("  4|     +--v  v--+  +--v   \n");
    printf("+--+    2   +--+   2    +--+\n");
    printf("|V2|<-------|V3|------->|V4|\n");
    printf("+--+        +--+        +--+\n");
    printf("  5|      8 |  | 4      |6  \n");
    printf("   +--v  v--+  +--v  v--+   \n");
    printf("      +--+   1    +--+      \n");
    printf("      |V5|<-------|V6|      \n");
    printf("      +--+        +--+      \n");
    printf("\n");

    printf("BFS from V0:\n");
    CleanFlag();
    BFS(G, 0);
    printf("\n");

    printf("DFS from V0:\n");
    CleanFlag();
    DFS(G, 0);
    printf("\n");

    int dist[VERTEX_NUMBER] = {INFINITY};
    int path[VERTEX_NUMBER] = {-1};
    if (Dijkstra(G, dist, path, 0))
    {
        printf("Dijkstra from V0: \n");
        printf("dist[]: ");
        for (int i = 0; i < VERTEX_NUMBER; i++)
        {
            printf("%d ", dist[i]);
        }
        printf("\n");
        printf("path[]: ");
        for (int i = 0; i < VERTEX_NUMBER; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Error in Dijkstra()...\n");
    }

    getchar();
    return 0;
}
