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
  Input:          空
  Return:         一个指向空列表的指针
*************************************************/
list_t CreateList(void);

/*************************************************
  Description:    销毁一个列表
  Input:          一个指向待销毁列表的指针
  Return:         空
*************************************************/
void DestroyList(list_t list);

/*************************************************
  Description:    求列表长度
  Input:          一个指向列表的指针
  Return:         列表长度
*************************************************/
int GetLength(list_t list);

/*************************************************
  Description:    判断列表已满
  Input:          一个指向列表的指针
  Return:         如果列表已满则返回true，否则返回false
*************************************************/
bool IsFull(list_t list);

/*************************************************
  Description:    判断列表已空
  Input:          一个指向列表的指针
  Return:         如果列表已空则返回true，否则返回false
*************************************************/
bool IsEmpty(list_t list);

/*************************************************
  Description:    取列表的第 i 个元素
                  0 <= i < GetLength(list)
  Input:          一个指向列表的指针，一个整数 i
  Return:         第 i 个元素
*************************************************/
item_t Get(list_t list, int i);

/*************************************************
  Description:    求 data 的下标
  Input:          一个指向列表的指针，一个元素 data
  Return:         下标 i 或者 ERROR
*************************************************/
int Find(list_t list, item_t data);

/*************************************************
  Description:    在指定位置插入一个元素
  Input:          一个指向列表的指针，下标 i ，元素 data
  Return:         空
*************************************************/
void Insert(list_t list, int i, item_t data);

/*************************************************
  Description:    在指定位置删除一个元素
  Input:          一个指向列表的指针，下标 i
  Return:         空
*************************************************/
void Delete(list_t list, int i);

/*************************************************
  Description:    输出列表内容
  Input:          一个指向列表的指针
  Return:         空
*************************************************/
void Print(list_t list);

/*************************************************
  Description:    就地逆置列表
  Input:          一个指向列表的指针
  Return:         空
*************************************************/
void Reverse(list_t list);

#endif
