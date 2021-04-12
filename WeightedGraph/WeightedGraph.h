/*
类型名称：加权图 (Weighted Graph)
对象集：G(V, E) 由一个非空的有限顶点集合 V 和一个有限边集合 E 组成。
操作集：对于任意的图 G ∈ graph_t ，顶点（的编号） V ∈ vertex_t，边（的权重） E ∈ edge_t ，有以下基本操作：
    1. graph_t CreateGraph(void)
    2. void DestroyGraph(graph_t G)
    3. void Link(graph_t G, vertex_t V1, vertex_t V2, edge_t E)
    4. bool IsAdjacent(graph_t G, vertex_t V1, vertex_t V2)
    5. void DFS(graph_t G, vertex_t startV, void (*pVisit)(vertex_t V))
    6. void BFS(graph_t G, vertex_t startV, void (*pVisit)(vertex_t V))
    7. bool Dijkstra(graph_t G, edge_t dist[], vertex_t path[], vertex_t startV)
    8. bool Floyd(graph_t G, edge_t dist[][VERTEX_NUMBER], vertex_t path[][VERTEX_NUMBER])
*/

#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

#define ERROR (-1)

#define VERTEX_NUMBER 7
#define NO_PATH INT_MAX

/* 注释掉此行变成无向图 */
// #define UNDIRECTED

typedef int vertex_t; // 顶点（的编号）

typedef int edge_t; // 边（的权重）

typedef struct graph *graph_t; // 图

struct graph
{
    int vertexNum;
    int edgeNum;
    edge_t matrix[VERTEX_NUMBER][VERTEX_NUMBER]; // 邻接矩阵
};

/*************************************************
  Description:    创建一个空图
  Parameter:      空
  Return:         一个指向空图的指针
*************************************************/
graph_t CreateGraph(void);

/*************************************************
  Description:    销毁一个图 G
  Parameter:      一个指向待销毁图的指针 G
  Return:         空
*************************************************/
void DestroyGraph(graph_t G);

/*************************************************
  Description:    以权重 E 链接一个图 G 的两个顶点 V1 和 V2
  Parameter:      一个指向图的指针 G
                  两个顶点 V1 V2
                  两个顶点连线的权重 E
  Return:         空
*************************************************/
void Link(graph_t G, vertex_t V1, vertex_t V2, edge_t E);

/*************************************************
  Description:    判断一个图 G 的两个顶点 V1 和 V2 之间是否链接
  Parameter:      一个指向图的指针 G
                  两个顶点 V1 V2
  Return:         如果两个顶点已链接则返回 true ，否则返回 false
*************************************************/
bool IsAdjacent(graph_t G, vertex_t V1, vertex_t V2);

/*************************************************
  Description:    深度优先遍历一个图 G
  Parameter:      一个指向图的指针 G
                  遍历起始点 startV
                  一个对遍历到的每个顶点进行操作的函数的指针 pVisit 
  Return:         空
*************************************************/
void DFS(graph_t G, vertex_t startV, void (*pVisit)(vertex_t V));

/*************************************************
  Description:    广度优先遍历一个图 G
  Parameter:      一个指向图的指针 G
                  遍历起始点 startV
                  一个对遍历到的每个顶点进行操作的函数的指针 pVisit 
  Return:         空
*************************************************/
void BFS(graph_t G, vertex_t startV, void (*pVisit)(vertex_t V));

/*************************************************
  Description:    Dijkstra算法遍历一个图 G
  Parameter:      一个指向图的指针 G
                  距离数组 dist
                  路径数组 path
                  遍历起始点 startV
  Return:         如果成功执行返回 true ，否则返回 false
*************************************************/
bool Dijkstra(graph_t G, edge_t dist[], vertex_t path[], vertex_t startV);

/*************************************************
  Description:    Floyd算法遍历一个图 G
  Parameter:      一个指向图的指针 G
                  距离数组 dist
                  路径数组 path
  Return:         如果成功执行返回 true ，否则返回 false
*************************************************/
bool Floyd(graph_t G, edge_t dist[][VERTEX_NUMBER], vertex_t path[][VERTEX_NUMBER]);

#endif
