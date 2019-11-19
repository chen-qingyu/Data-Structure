#include "Stack.h"

int main(int argc, char const *argv[])
{
    stack_t stack = CreateStack();
    element_t x = 233, y = 999;
    printf("The stack is empty? %s.\n", IsEmpty(stack) ? "yes" : "no");
    printf("Push a element: %d.\n", x);
    Push(stack, x);
    printf("Push a element: %d.\n", y);
    Push(stack, y);
    printf("The stack is empty? %s.\n", IsEmpty(stack) ? "yes" : "no");
    printf("Pop the element: %d.\n", Pop(stack));
    printf("Pop the element: %d.\n", Pop(stack));
    printf("The stack is empty? %s.\n", IsEmpty(stack) ? "yes" : "no");
    getchar();
    return 0;
}
