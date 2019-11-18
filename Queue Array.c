/*
循环队列(Circular Queue)
数组实现
对象集：有n(n>=0)个元素的有穷线性表
操作集：队列 queue 属于 queue_t ，元素 x 属于 element_t ，基本操作有：
    1. queue_t CreateQueue(void)
    2. bool IsFull(queue_t queue)
    3. bool IsEmpty(queue_t queue)
    4. bool Add(queue_t queue, element_t x)
    5. element_t Delete(queue_t queue)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define SIZE 100
#define ERROR (-1)

typedef int element_t;
typedef struct node * queue_t;
struct node
{
    element_t data[SIZE];
    int front;
    int rear;
};

queue_t CreateQueue(void);
bool IsFull(queue_t queue);
bool IsEmpty(queue_t queue);
bool Add(queue_t queue, element_t x);
element_t Delete(queue_t queue);

int main(int argc, char const *argv[])
{
    queue_t queue = CreateQueue();
    element_t x = 233;
    printf("The queue is empty? %s.\n", IsEmpty(queue) ? "yes" : "no");
    printf("Add a element: %d.\n", x);
    Add(queue, x);
    printf("The queue is empty? %s.\n", IsEmpty(queue) ? "yes" : "no");
    printf("Delete the element: %d.\n", Delete(queue));
    printf("The queue is empty? %s.\n", IsEmpty(queue) ? "yes" : "no");
    getchar();
    return 0;
}

queue_t CreateQueue(void)
{
    queue_t queue = (queue_t)malloc(sizeof(struct node));
    if (queue == NULL)
    {
        fprintf(stderr, "Failed to create new queue.\n");
        exit(-2);
    }

    queue->front = -1;
    queue->rear = -1;
    printf("Create a new queue successful.\n");
    return queue;
}

bool IsFull(queue_t queue)
{
    return (queue->rear + 1) % SIZE == queue->front;
}

bool IsEmpty(queue_t queue)
{
    return queue->rear == queue->front;
}

bool Add(queue_t queue, element_t x)
{
    if (IsFull(queue))
    {
        printf("The queue is full.\n");
        return false;
    }

    queue->rear = (queue->rear + 1) % SIZE;
    queue->data[queue->rear] = x;
    return true;
}

element_t Delete(queue_t queue)
{
    if (IsEmpty(queue))
    {
        printf("The queue is empty.\n");
        return ERROR;
    }

    queue->front = (queue->front + 1) % SIZE;
    return queue->data[queue->front];
}
