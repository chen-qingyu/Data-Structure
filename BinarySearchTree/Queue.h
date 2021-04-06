/*
队列(Queue)
对象集：有n(n>=0)个元素的有穷线性表
操作集：队列 queue 属于 queue_t ，元素 data 属于 tree_t ，基本操作有：
    1. queue_t CreateQueue(void)
    2. void DestroyQueue(queue_t queue)
    3. int GetLength(queue_t queue)
    4. bool IsFull(queue_t queue)
    5. bool IsEmpty(queue_t queue)
    6. void Enqueue(queue_t queue, tree_t data)
    7. tree_t Dequeue(queue_t queue)
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree.h"

#define SIZE 100

typedef struct queue *queue_t;
typedef struct tree *tree_t;

queue_t CreateQueue(void);
void DestroyQueue(queue_t queue);
int GetLength(queue_t queue);
bool IsFull(queue_t queue);
bool IsEmpty(queue_t queue);
void Enqueue(queue_t queue, tree_t data);
tree_t Dequeue(queue_t queue);

#endif
