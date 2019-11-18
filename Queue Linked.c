/*
队列(Queue)
不带头结点的单向链表实现
对象集：有n(n>=0)个元素的有穷线性表
操作集：队列 queue 属于 queue_t ，元素 x 属于 element_t ，基本操作有：
    1. queue_t CreateQueue(void)
    2. bool IsEmpty(queue_t queue)
    3. bool Add(queue_t queue, element_t x)
    4. element_t Delete(queue_t queue)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define ERROR (-1)

typedef int element_t;
typedef struct node * node_t;
typedef struct queue * queue_t;

struct node
{
    element_t data;
    node_t next;
};
struct queue
{
    node_t front;
    node_t rear;
};

queue_t CreateQueue(void);
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
    queue_t queue = (queue_t)malloc(sizeof(struct queue));
    if (queue == NULL)
    {
        fprintf(stderr, "Failed to create new queue.\n");
        exit(-2);
    }

    queue->front = NULL;
    queue->rear = NULL;
    printf("Create a new queue successful.\n");
    return queue;
}

bool IsEmpty(queue_t queue)
{
    return queue->front == NULL;
}

bool Add(queue_t queue, element_t x)
{
    node_t add = (node_t)malloc(sizeof(struct node));
    if (add == NULL)
    {
        fprintf(stderr, "Failed to create new node.\n");
        exit(-2);
    }

    add->data = x;
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

element_t Delete(queue_t queue)
{
    if (IsEmpty(queue))
    {
        printf("The queue is empty.\n");
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
    element_t x = del->data;
    free(del);
    return x;
}
