#include "Queue.h"

typedef struct node * node_t;

struct queue
{
    node_t front;
    node_t rear;
};

struct node
{
    item_t data;
    node_t next;
};

queue_t CreateQueue(void)
{
    queue_t queue = (queue_t)malloc(sizeof(struct queue));
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

int GetLength(queue_t queue)
{
    node_t current = queue->front;
    int length = 0;

    while (current)
    {
        current = current->next;
        length++;
    }

    return length;
}

bool IsFull(queue_t queue)
{
    return GetLength(queue) >= SIZE;
}

bool IsEmpty(queue_t queue)
{
    return queue->front == NULL;
}

bool Enqueue(queue_t queue, item_t data)
{
    if (IsFull(queue))
    {
        fprintf(stderr, "The queue is full.\n");
        return false;
    }

    node_t add = (node_t)malloc(sizeof(struct node));
    if (add == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    add->data = data;
    add->next = NULL;
    if (IsEmpty(queue))
    {
        queue->front = add;
        queue->rear = add;
    }
    else
    {
        queue->rear->next = add;
        queue->rear = add;
    }

    return true;
}

item_t Dequeue(queue_t queue)
{
    if (IsEmpty(queue))
    {
        fprintf(stderr, "The queue is empty.\n");
        return ERROR;
    }

    node_t del = queue->front;
    if (queue->front == queue->rear)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
    {
        queue->front = queue->front->next;
    }
    item_t data = del->data;
    free(del);

    return data;
}
