#include "Stack.h"

struct stack
{
    element_t data[SIZE];
    int top;
};

stack_t CreateStack(void)
{
    stack_t stack = (stack_t)malloc(sizeof(struct stack));
    if (stack == NULL)
    {
        fprintf(stderr, "Failed to create new stack.\n");
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
