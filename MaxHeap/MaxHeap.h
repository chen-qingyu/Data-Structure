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

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

/*************************************************
  Description:    创建一个空堆
  Parameter:      空
  Return:         一个指向空堆的指针
*************************************************/
heap_t CreateHeap(void);

/*************************************************
  Description:    销毁一个堆 heap
  Parameter:      一个指向待销毁堆的指针 heap
  Return:         空
*************************************************/
void DestroyHeap(heap_t heap);

/*************************************************
  Description:    判断堆 heap 是否已满
  Parameter:      一个指向堆的指针 heap
  Return:         如果堆已满则返回 true ，否则返回 false
*************************************************/
bool IsFull(heap_t heap);

/*************************************************
  Description:    判断堆 heap 是否已空
  Parameter:      一个指向堆的指针 heap
  Return:         如果堆已空则返回 true ，否则返回 false
*************************************************/
bool IsEmpty(heap_t heap);

/*************************************************
  Description:    在堆 heap 中插入一个元素 data
  Parameter:      一个指向堆的指针 heap
                  一个待插入元素 data
  Return:         空
*************************************************/
void Insert(heap_t heap, item_t data);

/*************************************************
  Description:    在堆 heap 中删除堆顶元素
  Parameter:      一个指向堆的指针 heap
  Return:         堆顶元素
*************************************************/
item_t Delete(heap_t heap);

/*************************************************
  Description:    构建最大堆 heap
  Parameter:      一个指向堆的指针 heap
  Return:         堆顶元素
*************************************************/
void BuildMaxHeap(heap_t heap);

#endif
