#include "MaxHeap.h"

/*******************************
Helper functions implementation.
*******************************/

/*******************************
Interface functions implementation.
*******************************/

heap_t CreateHeap(void)
{
    heap_t heap = (heap_t)malloc(sizeof(struct heap));
    if (heap == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }
    heap->data = (item_t *)malloc((HEAP_CAPACITY + 1) * sizeof(item_t));
    if (heap->data == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    heap->size = 0;
    heap->capacity = HEAP_CAPACITY;
    heap->data[0] = MAX_ITEM;

    return heap;
}

void DestroyHeap(heap_t heap)
{
    if (heap)
    {
        free(heap->data);
        free(heap);
        heap = NULL;
    }
}

bool IsFull(const heap_t heap)
{
    return heap->size == heap->capacity;
}

bool IsEmpty(const heap_t heap)
{
    return heap->size == 0;
}

void Insert(heap_t heap, item_t data)
{
    if (IsFull(heap))
    {
        printf("The heap is full.\n");
        return;
    }

    int i;
    for (i = ++heap->size; heap->data[i / 2] < data; i /= 2)
    {
        heap->data[i] = heap->data[i / 2];
    }
    heap->data[i] = data;
}

item_t Delete(heap_t heap)
{
    if (IsEmpty(heap))
    {
        printf("The heap is empty.\n");
        return ERROR;
    }

    int parent, child;
    item_t maxItem, tmp;

    maxItem = heap->data[1];
    tmp = heap->data[heap->size--];

    for (parent = 1; parent * 2 <= heap->size; parent = child)
    {
        child = parent * 2;
        if ((child != heap->size) && (heap->data[child] < heap->data[child + 1]))
        {
            child++;
        }
        if (tmp >= heap->data[child])
        {
            break;
        }
        else
        {
            heap->data[parent] = heap->data[child];
        }
    }
    heap->data[parent] = tmp;

    return maxItem;
}
