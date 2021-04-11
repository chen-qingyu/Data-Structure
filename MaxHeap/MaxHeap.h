/*
最大堆(Max Heap)
对象集：一棵完全二叉树，每个结点的元素值不小于其子结点的元素值
操作集：最大堆 heap 属于 heap_t，元素 data 属于 item_t，基本操作有：
    1. heap_t CreateHeap(void)
    2. void DestroyHeap(heap_t heap)
    3. bool IsFull(heap_t heap)
    4. bool IsEmpty(heap_t heap)
    5. void Insert(heap_t heap, item_t data)
    6. item_t Delete(heap_t heap)
    7. void BuildMaxHeap(heap_t heap)
*/

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR (-1)

#define HEAP_CAPACITY 100
#define MAX_ITEM INT_MAX

typedef struct heap *heap_t;

typedef int item_t;

struct heap
{
    item_t *data;
    int size;
    int capacity;
};

heap_t CreateHeap(void);
void DestroyHeap(heap_t heap);
bool IsFull(heap_t heap);
bool IsEmpty(heap_t heap);
void Insert(heap_t heap, item_t data);
item_t Delete(heap_t heap);
void BuildMaxHeap(heap_t heap);

#endif
