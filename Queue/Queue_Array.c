#include "Queue.h"

struct queue
{
    element_t data[SIZE + 1]; // 循环队列，数组容量为队列最大有效长度加一
    int front;
    int rear;
};

queue_t CreateQueue(void)
{
    queue_t queue = (queue_t)malloc(sizeof(struct queue));
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

int GetLength(queue_t queue)
{
    return (queue->rear - queue->front + (SIZE + 1)) % (SIZE + 1);
}

bool IsFull(queue_t queue)
{
    return GetLength(queue) >= SIZE;
}

bool IsEmpty(queue_t queue)
{
    return GetLength(queue) <= 0;
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
