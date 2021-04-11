#include "Queue.h"

int main(void)
{
    queue_t queue = CreateQueue();
    item_t a[] = {1, 2, 3, 4};

    printf("The queue is empty? %s.\n\n", IsEmpty(queue) ? "yes" : "no");

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        Enqueue(queue, a[i]);
        printf("Enqueue an item: %d.\n", a[i]);
    }

    printf("The queue is empty? %s.\n\n", IsEmpty(queue) ? "yes" : "no");

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("Dequeue an item: %d.\n", Dequeue(queue));
    }

    printf("The queue is empty? %s.\n\n", IsEmpty(queue) ? "yes" : "no");

    DestroyQueue(queue);
    return 0;
}
