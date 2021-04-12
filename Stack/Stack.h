/*
栈(Stack)
对象集：有n(n>=0)个元素的有穷线性表
操作集：栈 stack 属于 stack_t ，元素 data 属于 item_t ，基本操作有：
    1. stack_t CreateStack(void)
    2. void DestroyStack(stack_t stack)
    3. int GetLength(const stack_t stack)
    4. bool IsFull(const stack_t stack)
    5. bool IsEmpty(const stack_t stack)
    6. void Push(stack_t stack, item_t data)
    7. item_t Pop(stack_t stack)
    8. item_t Top(const stack_t stack)
*/

#ifndef STACK_H
#define STACK_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR (-1)

#define STACK_CAPACITY 100

typedef int item_t;

typedef struct stack *stack_t;

/*************************************************
  Description:    创建一个空栈
  Parameter:      空
  Return:         一个指向空栈的指针
*************************************************/
stack_t CreateStack(void);

/*************************************************
  Description:    销毁一个栈 stack
  Parameter:      一个指向待销毁栈的指针 stack
  Return:         空
*************************************************/
void DestroyStack(stack_t stack);

/*************************************************
  Description:    求栈 stack 的长度
  Parameter:      一个指向栈的指针 stack
  Return:         栈长度
*************************************************/
int GetLength(const stack_t stack);

/*************************************************
  Description:    判断栈 stack 是否已满
  Parameter:      一个指向栈的指针 stack
  Return:         如果栈已满则返回 true ，否则返回 false
*************************************************/
bool IsFull(const stack_t stack);

/*************************************************
  Description:    判断栈 stack 是否已空
  Parameter:      一个指向栈的指针 stack
  Return:         如果栈已空则返回 true ，否则返回 false
*************************************************/
bool IsEmpty(const stack_t stack);

/*************************************************
  Description:    入栈，将元素 data 压入到栈 stack 的顶部
  Parameter:      一个指向栈的指针 stack
                  一个待入栈的元素 data
  Return:         空
*************************************************/
void Push(stack_t stack, item_t data);

/*************************************************
  Description:    出栈，将栈 stack 的顶部的元素弹出来
  Parameter:      一个指向栈的指针 stack
  Return:         栈顶元素
*************************************************/
item_t Pop(stack_t stack);

/*************************************************
  Description:    检查栈 stack 的顶部元素，不改变栈
  Parameter:      一个指向栈的指针 stack
  Return:         栈顶元素
*************************************************/
item_t Top(const stack_t stack);

#endif
