/*
最大堆(MaxHeap)
对象集：完全二叉树，每个结点的元素值不小于其子结点的元素值
操作集：最大堆 heap 属于 heap_t，元素 data 属于 item_t，基本操作有：
    1. heap_t CreateHeap(void)
    2. bool IsFull(heap_t heap)
    3. bool IsEmpty(heap_t heap)
    4. bool Insert(heap_t heap, item_t data)
    5. item_t Delete(heap_t heap)
    6. void BuildHeap(heap_t heap)
*/

#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ERROR (-1)
#define SIZE 100
#define MAX_ITEM 1000

typedef struct heap *heap_t;

typedef int item_t;

struct heap
{
    item_t *data;
    int size;
    int capacity;
};

heap_t CreateHeap(void);
bool IsFull(heap_t heap);
bool IsEmpty(heap_t heap);
bool Insert(heap_t heap, item_t data);
item_t Delete(heap_t heap);
void BuildHeap(heap_t heap);

#endif
