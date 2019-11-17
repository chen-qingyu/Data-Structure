/*
堆栈(Stack)
链表实现
对象集：有n(n>=0)个元素的有穷线性表
操作集：堆栈 stack 属于 stack_t ，元素 x 属于 element_t ，基本操作有：
    1. stack_t CreateStack(void)
    2. bool IsEmpty(stack_t stack)
    3. bool Push(stack_t stack, element_t x)
    4. element_t Pop(stack_t stack)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define ERROR (-1)

typedef int element_t;
typedef struct node * stack_t;
struct node
{
    element_t data;
    stack_t next;
};

stack_t CreateStack(void);
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

    stack->next = NULL;
    printf("Create a new stack successful.\n");
    return stack;
}

bool IsEmpty(stack_t stack)
{
    return stack->next == NULL;
}

bool Push(stack_t stack, element_t x)
{
    stack_t top = (stack_t)malloc(sizeof(struct node));
    if (top == NULL)
    {
        fprintf(stderr, "Failed to create new node.\n");
        exit(-2);
    }

    top->data = x;
    top->next = stack->next;
    stack->next = top;
    return true;
}

element_t Pop(stack_t stack)
{
    if (IsEmpty(stack))
    {
        printf("The stack is empty.\n");
        return ERROR;
    }

    stack_t top = stack->next;
    stack->next = top->next;
    element_t x = top->data;
    free(top);
    return x;
}
