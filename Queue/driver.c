#include "Queue.h"

int main(int argc, char const *argv[])
{
    queue_t queue = CreateQueue();
    element_t x = 233, y = 999;
    printf("The queue is empty? %s.\n", IsEmpty(queue) ? "yes" : "no");
    printf("Add a element: %d.\n", x);
    Add(queue, x);
    printf("Add a element: %d.\n", y);
    Add(queue, y);
    printf("The queue is empty? %s.\n", IsEmpty(queue) ? "yes" : "no");
    printf("Delete the element: %d.\n", Delete(queue));
    printf("Delete the element: %d.\n", Delete(queue));
    printf("The queue is empty? %s.\n", IsEmpty(queue) ? "yes" : "no");
    getchar();
    return 0;
}
