/*
队列(Queue)
对象集：有n(n>=0)个元素的有穷线性表
操作集：队列 queue 属于 queue_t ，元素 data 属于 item_t ，基本操作有：
    1. queue_t CreateQueue(void)
    2. int GetLength(queue_t queue)
    3. bool IsFull(queue_t queue)
    4. bool IsEmpty(queue_t queue)
    5. bool Enqueue(queue_t queue, item_t data)
    6. item_t Dequeue(queue_t queue)
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ERROR (-1)

#define SIZE 100

typedef int item_t;

typedef struct queue * queue_t;

queue_t CreateQueue(void);
int GetLength(queue_t queue);
bool IsFull(queue_t queue);
bool IsEmpty(queue_t queue);
bool Enqueue(queue_t queue, item_t data);
item_t Dequeue(queue_t queue);

#endif
