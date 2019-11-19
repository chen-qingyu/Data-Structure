/*
队列(Queue)
对象集：有n(n>=0)个元素的有穷线性表
操作集：队列 queue 属于 queue_t ，元素 data 属于 element_t ，基本操作有：
    1. queue_t CreateQueue(void)
    2. int GetLength(queue_t queue)
    3. bool IsFull(queue_t queue)
    4. bool IsEmpty(queue_t queue)
    5. bool Add(queue_t queue, element_t data)
    6. element_t Delete(queue_t queue)
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define SIZE 100
#define ERROR (-1)

typedef int element_t;

typedef struct queue * queue_t;

queue_t CreateQueue(void);
int GetLength(queue_t queue);
bool IsFull(queue_t queue);
bool IsEmpty(queue_t queue);
bool Add(queue_t queue, element_t data);
element_t Delete(queue_t queue);

#endif
