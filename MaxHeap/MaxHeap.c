#include "MaxHeap.h"

heap_t CreateHeap(void)
{
    heap_t heap = (heap_t)malloc(sizeof(struct heap));
    heap->data = (item_t *)malloc((SIZE + 1) * sizeof(item_t));
    heap->size = 0;
    heap->capacity = SIZE;
    heap->data[0] = MAX_ITEM;

    return heap;
}

bool IsFull(heap_t heap)
{
    return heap->size == heap->capacity;
}

bool IsEmpty(heap_t heap)
{
    return heap->size == 0;
}

bool Insert(heap_t heap, item_t data)
{
    if (IsFull(heap))
    {
        printf("The heap is full.\n");
        return false;
    }

    int i;
    for (i = ++heap->size; heap->data[i / 2] < data; i /= 2)
    {
        heap->data[i] = heap->data[i / 2];
    }
    heap->data[i] = data;

    return true;
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

void BuildMaxHeap(heap_t heap)
{
    int parent, child;
    item_t tmp;

    for (int i = heap->size / 2; i > 0; i--)
    {
        tmp = heap->data[i];
        for (parent = i; parent * 2 <= heap->size; parent = child)
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
    }
}
