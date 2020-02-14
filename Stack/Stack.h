/*
栈(Stack)
对象集：有n(n>=0)个元素的有穷线性表
操作集：栈 stack 属于 stack_t ，元素 data 属于 item_t ，基本操作有：
    1. stack_t CreateStack(void)
    2. int GetLength(stack_t stack)
    3. bool IsFull(stack_t stack)
    4. bool IsEmpty(stack_t stack)
    5. bool Push(stack_t stack, item_t data)
    6. item_t Pop(stack_t stack)
*/

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 100
#define ERROR (-1)

typedef int item_t;

typedef struct stack * stack_t;

stack_t CreateStack(void);
int GetLength(stack_t stack);
bool IsFull(stack_t stack);
bool IsEmpty(stack_t stack);
bool Push(stack_t stack, item_t data);
item_t Pop(stack_t stack);

#endif
