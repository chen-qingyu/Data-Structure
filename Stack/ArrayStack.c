#include "Stack.h"

struct stack
{
    item_t data[STACK_CAPACITY];
    int top;
};

/*******************************
Helper functions implementation.
*******************************/

/*******************************
Interface functions implementation.
*******************************/

stack_t CreateStack(void)
{
    stack_t stack = (stack_t)malloc(sizeof(struct stack));
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    stack->top = -1;

    return stack;
}

void DestroyStack(stack_t stack)
{
    if (stack)
    {
        free(stack);
        stack = NULL;
    }
}

int GetLength(const stack_t stack)
{
    return stack->top + 1;
}

bool IsFull(const stack_t stack)
{
    return GetLength(stack) >= STACK_CAPACITY;
}

bool IsEmpty(const stack_t stack)
{
    return GetLength(stack) <= 0;
}

void Push(stack_t stack, item_t data)
{
    if (IsFull(stack))
    {
        fprintf(stderr, "The stack is full.\n");
        return;
    }

    stack->data[++(stack->top)] = data;
}

item_t Pop(stack_t stack)
{
    if (IsEmpty(stack))
    {
        fprintf(stderr, "The stack is empty.\n");
        return ERROR;
    }

    return stack->data[(stack->top)--];
}

item_t Top(const stack_t stack)
{
    if (IsEmpty(stack))
    {
        fprintf(stderr, "The stack is empty.\n");
        return ERROR;
    }

    return stack->data[stack->top];
}
