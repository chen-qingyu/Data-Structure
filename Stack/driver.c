#include "Stack.h"

int main(int argc, char const *argv[])
{
    stack_t stack = CreateStack();
    item_t a[] = {1, 2, 3, 4};

    printf("The stack is empty? %s.\n\n", IsEmpty(stack) ? "yes" : "no");

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        if (Push(stack, a[i]))
        {
            printf("Push an item: %d.\n", a[i]);
        }
        else
        {
            printf("Failed to push items.\n");
        }
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
