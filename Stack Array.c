/*
堆栈(Stack)
数组实现
对象集：有n(n>=0)个元素的有穷线性表
操作集：堆栈 stack 属于 stack_t ，元素 x 属于 element_t ，基本操作有：
    1. stack_t CreateStack(void)
    2. bool IsFull(stack_t stack)
    3. bool IsEmpty(stack_t stack)
    4. bool Push(stack_t stack, element_t x)
    5. element_t Pop(stack_t stack)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define SIZE 100
#define ERROR (-1)

typedef int element_t;
typedef struct node * stack_t;
struct node
{
    element_t data[SIZE];
    int top;
};

stack_t CreateStack(void);
bool IsFull(stack_t stack);
bool IsEmpty(stack_t stack);
bool Push(stack_t stack, element_t x);
element_t Pop(stack_t stack);

int main(int argc, char const *argv[])
{
    stack_t stack = CreateStack();
    element_t x = 233;
    printf("The stack is empty? %s.\n", IsEmpty(stack) ? "yes" : "no");
    printf("Push a element: %d.\n", x);
    Push(stack, x);
    printf("The stack is empty? %s.\n", IsEmpty(stack) ? "yes" : "no");
    printf("Pop the element: %d.\n", Pop(stack));
    printf("The stack is empty? %s.\n", IsEmpty(stack) ? "yes" : "no");
    getchar();
    return 0;
}

stack_t CreateStack(void)
{
    stack_t stack = (stack_t)malloc(sizeof(struct node));
    if (stack == NULL)
    {
        fprintf(stderr, "Failed to create new stack.\n");
        exit(-2);
    }

    stack->top = -1;
    printf("Create a new stack successful.\n");
    return stack;
}

bool IsFull(stack_t stack)
{
    return stack->top == (SIZE - 1);
}

bool IsEmpty(stack_t stack)
{
    return stack->top == -1;
}

bool Push(stack_t stack, element_t x)
{
    if (IsFull(stack))
    {
        printf("The stack is full.\n");
        return false;
    }

    stack->data[++(stack->top)] = x;
    return true;
}

element_t Pop(stack_t stack)
{
    if (IsEmpty(stack))
    {
        printf("The stack is empty.\n");
        return ERROR;
    }

    return stack->data[(stack->top)--];
}
