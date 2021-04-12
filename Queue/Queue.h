/*
队列(Queue)
对象集：有n(n>=0)个元素的有穷线性表
操作集：队列 queue 属于 queue_t ，元素 data 属于 item_t ，基本操作有：
    1. queue_t CreateQueue(void)
    2. void DestroyQueue(queue_t queue)
    3. int GetLength(queue_t queue)
    4. bool IsFull(queue_t queue)
    5. bool IsEmpty(queue_t queue)
    6. void Enqueue(queue_t queue, item_t data)
    7. item_t Dequeue(queue_t queue)
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR (-1)

#define QUEUE_CAPACITY 100

typedef int item_t;

typedef struct queue *queue_t;

/*************************************************
  Description:    创建一个空队列
  Parameter:      空
  Return:         一个指向空队列的指针
*************************************************/
queue_t CreateQueue(void);

/*************************************************
  Description:    销毁一个队列 queue
  Parameter:      一个指向待销毁队列的指针 queue
  Return:         空
*************************************************/
void DestroyQueue(queue_t queue);

/*************************************************
  Description:    求队列 queue 的长度
  Parameter:      一个指向队列的指针 queue
  Return:         队列长度
*************************************************/
int GetLength(queue_t queue);

/*************************************************
  Description:    判断队列 queue 是否已满
  Parameter:      一个指向队列的指针 queue
  Return:         如果队列已满则返回 true ，否则返回 false
*************************************************/
bool IsFull(queue_t queue);

/*************************************************
  Description:    判断队列 queue 是否已空
  Parameter:      一个指向队列的指针 queue
  Return:         如果队列已空则返回 true ，否则返回 false
*************************************************/
bool IsEmpty(queue_t queue);

/*************************************************
  Description:    入队，将元素 data 插入到队列 queue 的尾部
  Parameter:      一个指向队列的指针 queue
                  一个待入队的元素 data
  Return:         空
*************************************************/
void Enqueue(queue_t queue, item_t data);

/*************************************************
  Description:    出队，将队列 queue 的队首元素出队
  Parameter:      一个指向队列的指针 queue
  Return:         队首元素
*************************************************/
item_t Dequeue(queue_t queue);

#endif
