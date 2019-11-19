#include "Stack.h"

struct stack
{
    element_t data;
    stack_t next;
};

stack_t CreateStack(void)
{
    stack_t stack = (stack_t)malloc(sizeof(struct stack));
    if (stack == NULL)
    {
        fprintf(stderr, "Failed to create new stack.\n");
        exit(-2);
    }

    stack->next = NULL;
    printf("Create a new stack successful.\n");
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

bool Push(stack_t stack, element_t x)
{
    if (IsFull(stack))
    {
        printf("The stack is full.\n");
        return false;
    }

    stack_t top = (stack_t)malloc(sizeof(struct stack));
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
