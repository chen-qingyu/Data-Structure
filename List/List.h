/*
列表(List)
对象集：n(n>=0)个元素构成的有序序列 a1, a2, a3 ... an.
操作集：列表 list 属于 list_t ，整数 i 表示元素下标(从0开始)，元素 data 属于 item_t ，基本操作有：
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
    11. void Reverse(list_t list);
*/

#ifndef LIST_H
#define LIST_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR (-1)

#define LIST_CAPACITY 128

typedef int item_t;

typedef struct list *list_t;

/*************************************************
  Description:    创建一个空列表
  Parameter:      空
  Return:         一个指向空列表的指针
*************************************************/
list_t CreateList(void);

/*************************************************
  Description:    销毁一个列表 list
  Parameter:      一个指向待销毁列表的指针 list
  Return:         空
*************************************************/
void DestroyList(list_t list);

/*************************************************
  Description:    求列表 list 的长度
  Parameter:      一个指向列表的指针 list
  Return:         列表长度
*************************************************/
int GetLength(list_t list);

/*************************************************
  Description:    判断列表 list 是否已满
  Parameter:      一个指向列表的指针 list
  Return:         如果列表已满则返回 true ，否则返回 false
*************************************************/
bool IsFull(list_t list);

/*************************************************
  Description:    判断列表 list 是否已空
  Parameter:      一个指向列表的指针 list
  Return:         如果列表已空则返回 true ，否则返回 false
*************************************************/
bool IsEmpty(list_t list);

/*************************************************
  Description:    取列表 list 的第 i 个元素
  Parameter:      一个指向列表的指针 list
                  下标 i (0 <= i < GetLength(list))
  Return:         第 i 个元素
*************************************************/
item_t Get(list_t list, int i);

/*************************************************
  Description:    求元素 data 在列表 list 中的下标
  Parameter:      一个指向列表的指针 list
                  一个待寻找元素 data
  Return:         待寻找元素 data 的下标 i 或者 ERROR
*************************************************/
int Find(list_t list, item_t data);

/*************************************************
  Description:    在列表 list 的下标为 i 的位置上插入一个元素 data
  Parameter:      一个指向列表的指针 list
                  下标 i (0 <= i <= GetLength(list))
                  待插入元素 data
  Return:         空
*************************************************/
void Insert(list_t list, int i, item_t data);

/*************************************************
  Description:    从列表 list 当中删除下标为 i 的元素
  Parameter:      一个指向列表的指针 list
                  下标 i (0 <= i < GetLength(list))
  Return:         空
*************************************************/
void Delete(list_t list, int i);

/*************************************************
  Description:    输出列表 list 的内容
  Parameter:      一个指向列表的指针 list
  Return:         空
*************************************************/
void Print(list_t list);

/*************************************************
  Description:    就地逆置列表 list
  Parameter:      一个指向列表的指针 list
  Return:         空
*************************************************/
void Reverse(list_t list);

#endif
