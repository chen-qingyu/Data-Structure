/*
二叉搜索树(Binary Search Tree)
对象集：一个有穷的结点集合。若不为空，则由根结点和其左、右二叉子树组成。
操作集：二叉树 tree 属于 tree_t，结点数据 data 属于 item_t ，基本操作有：
    1. tree_t CreateTree(void);
    2. void Traversal(tree_t tree, int type);
    3. tree_t Find(tree_t tree, item_t data);
    4. tree_t FindMin(tree_t tree);
    5. tree_t FindMax(tree_t tree);
    6. tree_t Insert(tree_t tree, item_t data);
    7. tree_t Delete(tree_t tree, item_t data);
*/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ERROR NULL

#define PRE_ORDER 1
#define IN_ORDER 2
#define POST_ORDER 3
#define LEVEL_ORDER 4

typedef int item_t;

typedef struct tree *tree_t;

struct tree
{
    item_t data;
    tree_t left;
    tree_t right;
};

#include "Queue.h"

tree_t CreateTree(void);
void Traversal(tree_t tree, int type);
tree_t Find(tree_t tree, item_t data);
tree_t FindMin(tree_t tree);
tree_t FindMax(tree_t tree);
tree_t Insert(tree_t tree, item_t data);
tree_t Delete(tree_t tree, item_t data);

#endif
