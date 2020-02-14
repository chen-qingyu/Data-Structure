/*
队列(Queue)
对象集：有n(n>=0)个元素的有穷线性表
操作集：队列 queue 属于 queue_t ，元素 data 属于 tree_t ，基本操作有：
    1. queue_t CreateQueue(void)
    2. int GetLength(queue_t queue)
    3. bool IsFull(queue_t queue)
    4. bool IsEmpty(queue_t queue)
    5. bool AddQ(queue_t queue, tree_t data)
    6. tree_t DeleteQ(queue_t queue)
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "BinaryTree.h"

#define SIZE 100

typedef struct queue * queue_t;

struct queue
{
    tree_t data[SIZE + 1]; // 循环队列，数组容量为队列最大有效长度加一
    int front;
    int rear;
};

queue_t CreateQueue(void);
int GetLength(queue_t queue);
bool IsFull(queue_t queue);
bool IsEmpty(queue_t queue);
bool AddQ(queue_t queue, tree_t data);
tree_t DeleteQ(queue_t queue);

#endif
