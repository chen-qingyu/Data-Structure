#include "Stack.h"

struct stack
{
    item_t data[SIZE];
    int top;
};

stack_t CreateStack(void)
{
    stack_t stack = (stack_t)malloc(sizeof(struct stack));
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    stack->top = -1;
    printf("Create a new stack successful.\n");
    return stack;
}

int GetLength(stack_t stack)
{
    return stack->top + 1;
}

bool IsFull(stack_t stack)
{
    return GetLength(stack) >= SIZE;
}

bool IsEmpty(stack_t stack)
{
    return GetLength(stack) <= 0;
}

bool Push(stack_t stack, item_t data)
{
    if (IsFull(stack))
    {
        printf("The stack is full.\n");
        return false;
    }

    stack->data[++(stack->top)] = data;
    return true;
}

item_t Pop(stack_t stack)
{
    if (IsEmpty(stack))
    {
        printf("The stack is empty.\n");
        return ERROR;
    }

    return stack->data[(stack->top)--];
}
