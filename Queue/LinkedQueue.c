#include "Queue.h"

typedef struct node *node_t;

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

/*******************************
Helper functions implementation.
*******************************/

/*******************************
Interface functions implementation.
*******************************/

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

void DestroyQueue(queue_t queue)
{
    if (queue)
    {
        node_t head = queue->front;
        node_t current;

        while (head)
        {
            current = head->next;
            free(head);
            head = current;
        }

        free(queue);
        queue = NULL;
    }
}

int GetLength(const queue_t queue)
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

bool IsFull(const queue_t queue)
{
    return GetLength(queue) >= QUEUE_CAPACITY;
}

bool IsEmpty(const queue_t queue)
{
    return queue->front == NULL;
}

void Enqueue(queue_t queue, item_t data)
{
    if (IsFull(queue))
    {
        fprintf(stderr, "The queue is full.\n");
        return;
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
