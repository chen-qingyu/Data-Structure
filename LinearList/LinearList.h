/*
线性表(Linear List)
对象集：n(n>=0)个元素构成的有序序列 a1, a2, a3 ... an
操作集：线性表 list 属于 list_t ，整数 i 表示元素下标(从0开始)，元素 data 属于 item_t ，基本操作有：
    1. list_t CreateList(void)
    2. int GetLength(list_t list)
    3. bool IsFull(list_t list)
    4. bool IsEmpty(list_t list)
    5. item_t FindByIndex(int i, list_t list)
    6. int Find(item_t data, list_t list)
    7. bool Insert(item_t data, int i, list_t list)
    8. bool Delete(int i, list_t list)
    9. void Print(list_t list)
   10. bool LinkList(list_t list1, list_t list2)
*/

#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define SIZE 100
#define ERROR (-1)

typedef int item_t;

typedef struct list * list_t;

list_t CreateList(void);
int GetLength(list_t list);
bool IsFull(list_t list);
bool IsEmpty(list_t list);
item_t FindByIndex(int i, list_t list);
int Find(item_t data, list_t list);
bool Insert(item_t data, int i, list_t list);
bool Delete(int i, list_t list);
void Print(list_t list);
bool LinkList(list_t list1, list_t list2);

#endif
