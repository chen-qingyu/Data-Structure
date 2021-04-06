/*
链表(Linked List)
对象集：n(n>=0)个元素构成的有序序列 a1, a2, a3 ... an.
操作集：线性表 list 属于 list_t ，整数 i 表示元素下标(从0开始)，元素 data 属于 item_t ，基本操作有：
    1. list_t CreateList(void)
    2. void DestroyList(list_t list)
    3. int GetLength(list_t list)
    4. bool IsFull(list_t list)
    5. bool IsEmpty(list_t list)
    6. item_t Get(list_t list, int i)
    7. int Find(list_t list, item_t data)
    8. void Insert(list_t list, int i, item_t data)
    9. void Delete(list_t list, int i)
    10. void Print(list_t list)
    11. void LinkList(list_t list1, list_t list2)
    12. void Reverse(list_t list);
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int item_t;

typedef struct list *list_t;

list_t CreateList(void);
void DestroyList(list_t list);
int GetLength(list_t list);
bool IsFull(list_t list);
bool IsEmpty(list_t list);
item_t Get(list_t list, int i);
int Find(list_t list, item_t data);
void Insert(list_t list, int i, item_t data);
void Delete(list_t list, int i);
void Print(list_t list);
void LinkList(list_t list1, list_t list2);
void Reverse(list_t list);

#endif
