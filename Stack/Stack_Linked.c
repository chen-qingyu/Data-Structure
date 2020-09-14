#include "Stack.h"

struct stack
{
    item_t data;
    stack_t next;
};

stack_t CreateStack(void)
{
    stack_t stack = (stack_t)malloc(sizeof(struct stack));
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    stack->next = NULL;

    return stack;
}

int GetLength(stack_t stack)
{
    stack_t current = stack->next;
    int length = 0;

    while (current)
    {
        current = current->next;
        length++;
    }

    return length;
}

bool IsFull(stack_t stack)
{
    return GetLength(stack) >= SIZE;
}

bool IsEmpty(stack_t stack)
{
    return stack->next == NULL;
}

void Push(stack_t stack, item_t data)
{
    if (IsFull(stack))
    {
        fprintf(stderr, "The stack is full.\n");
        return;
    }

    stack_t top = (stack_t)malloc(sizeof(struct stack));
    if (top == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    top->data = data;
    top->next = stack->next;
    stack->next = top;
}

item_t Pop(stack_t stack)
{
    if (IsEmpty(stack))
    {
        fprintf(stderr, "The stack is empty.\n");
        return ERROR;
    }

    stack_t top = stack->next;
    stack->next = top->next;
    item_t data = top->data;
    free(top);

    return data;
}
