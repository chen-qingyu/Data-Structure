#include "Queue.h"

int main(void)
{
    queue_t queue = CreateQueue();
    item_t a[] = {1, 2, 3, 4};

    printf("The queue is empty? %s.\n\n", IsEmpty(queue) ? "yes" : "no");

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        if (Enqueue(queue, a[i]))
        {
            printf("Enqueue an item: %d.\n", a[i]);
        }
        else
        {
            printf("Failed to add items.\n");
        }
    }

    printf("The queue is empty? %s.\n\n", IsEmpty(queue) ? "yes" : "no");

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("Dequeue an item: %d.\n", Dequeue(queue));
    }

    printf("The queue is empty? %s.\n\n", IsEmpty(queue) ? "yes" : "no");

    getchar();
    return 0;
}
