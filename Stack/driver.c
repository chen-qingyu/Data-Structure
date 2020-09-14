#include "Stack.h"

int main(void)
{
    stack_t stack = CreateStack();
    item_t a[] = {1, 2, 3, 4};

    printf("The stack is empty? %s.\n\n", IsEmpty(stack) ? "yes" : "no");

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        Push(stack, a[i]);
        printf("Push an item: %d.\n", a[i]);
    }

    printf("The stack is empty? %s.\n\n", IsEmpty(stack) ? "yes" : "no");

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("Pop an item: %d.\n", Pop(stack));
    }

    printf("The stack is empty? %s.\n\n", IsEmpty(stack) ? "yes" : "no");

    getchar();
    return 0;
}
