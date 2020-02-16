/*
类型名称：加权无向图 (Weighted Undirected Graph)
对象集：G(V, E) 由一个非空的有限顶点集合 V 和一个有限边集合 E 组成
操作集：对于任意图 graph ∈ graph_t ，以及 vertex ∈ vertex_t, edge ∈ edge_t ，有以下基本操作：
    1. graph_t CreateGraph(void);
    2. void Link(graph_t G, vertex_t V1, vertex_t V2, weight_t weight);
    3. bool IsAdjacent(graph_t G, vertex_t V1, vertex_t V2);
    4. void Visit(vertex_t V);
    5. void DFS(graph_t G, vertex_t V);
    6. void BFS(graph_t G, vertex_t V);
    7. void CleanFlag(void);
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define VERTEX_NUMBER 10
#define ERROR (-1)

typedef int vertex_t; // 结点

typedef int weight_t; // 边的权重

typedef struct graph *graph_t; // 图
struct graph
{
    int vertexNum;
    int edgeNum;
    weight_t matrix[VERTEX_NUMBER][VERTEX_NUMBER]; // 10x10 邻接矩阵
};

#include "Queue.h"

graph_t CreateGraph(void);
void Link(graph_t G, vertex_t V1, vertex_t V2, weight_t weight);
bool IsAdjacent(graph_t G, vertex_t V1, vertex_t V2);
void Visit(vertex_t V);
void DFS(graph_t G, vertex_t V);
void BFS(graph_t G, vertex_t V);
void CleanFlag(void);

#endif
