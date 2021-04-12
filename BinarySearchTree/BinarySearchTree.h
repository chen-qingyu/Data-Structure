/*
二叉搜索树(Binary Search Tree)
对象集：一个有穷的结点集合。若不为空，则由根结点和其左、右二叉子树组成。
操作集：二叉树 tree 属于 tree_t，结点数据 data 属于 item_t ，基本操作有：
    1. tree_t CreateTree(void)
    2. void DestroyTree(tree_t tree)
    3. void Traversal(tree_t tree, traversal_t type, void (*pTrav)(item_t data))
    4. tree_t Find(const tree_t tree, const item_t data)
    5. tree_t FindMin(const tree_t tree)
    6. tree_t FindMax(const tree_t tree)
    7. tree_t Insert(tree_t tree, const item_t data)
    8. tree_t Delete(tree_t tree, const item_t data)
*/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

#define ERROR NULL

typedef enum
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER,
    LEVEL_ORDER
} traversal_t;

typedef int item_t;

typedef struct tree *tree_t;

struct tree
{
    item_t data;
    tree_t left;
    tree_t right;
};

/*************************************************
  Description:    创建一个空二叉搜索树
  Parameter:      空
  Return:         一个指向空二叉搜索树的指针
*************************************************/
tree_t CreateTree(void);

/*************************************************
  Description:    销毁一个二叉搜索树 tree
  Parameter:      一个指向待销毁二叉搜索树的指针 tree
  Return:         空
*************************************************/
void DestroyTree(tree_t tree);

/*************************************************
  Description:    遍历一个二叉搜索树 tree
  Parameter:      一个指向二叉搜索树的指针 tree
                  一个枚举遍历类型 type
                    - PRE_ORDER   先序遍历
                    - IN_ORDER    中序遍历
                    - POST_ORDER  后序遍历
                    - LEVEL_ORDER 层次遍历
                  一个对遍历到的每个元素进行操作的函数的指针 pTrav 
  Return:         空
*************************************************/
void Traversal(tree_t tree, traversal_t type, void (*pTrav)(item_t data));

/*************************************************
  Description:    在一个二叉搜索树 tree 中寻找元素 data
  Parameter:      一个指向二叉搜索树的指针 tree
                  一个待寻找元素 data
  Return:         元素 data 所在的结点或者 NULL
*************************************************/
tree_t Find(const tree_t tree, const item_t data);

/*************************************************
  Description:    在一个二叉搜索树 tree 中寻找最小元素
  Parameter:      一个指向二叉搜索树的指针 tree
  Return:         最小元素所在的结点或者 NULL
*************************************************/
tree_t FindMin(const tree_t tree);

/*************************************************
  Description:    在一个二叉搜索树 tree 中寻找最大元素
  Parameter:      一个指向二叉搜索树的指针 tree
  Return:         最大元素所在的结点或者 NULL
*************************************************/
tree_t FindMax(const tree_t tree);

/*************************************************
  Description:    在一个二叉搜索树 tree 中插入元素 data
  Parameter:      一个指向二叉搜索树的指针 tree
                  一个待插入元素 data
  Return:         插入元素后的二叉搜索树 tree
*************************************************/
tree_t Insert(tree_t tree, const item_t data);

/*************************************************
  Description:    在一个二叉搜索树 tree 中删除元素 data
  Parameter:      一个指向二叉搜索树的指针 tree
                  一个待删除元素 data
  Return:         删除元素后的二叉搜索树 tree
*************************************************/
tree_t Delete(tree_t tree, const item_t data);

#endif
