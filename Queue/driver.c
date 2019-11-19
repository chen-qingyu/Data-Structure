#include "Queue.h"

int main(int argc, char const *argv[])
{
    queue_t queue = CreateQueue();
    item_t a[] = {1, 2, 3, 4};

    printf("The queue is empty? %s.\n\n", IsEmpty(queue) ? "yes" : "no");

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        if (Add(queue, a[i]))
        {
            printf("Add an item: %d.\n", a[i]);
        }
        else
        {
            printf("Failed to add items.\n");
        }
    }

    printf("The queue is empty? %s.\n\n", IsEmpty(queue) ? "yes" : "no");

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("Delete an item: %d.\n", Delete(queue));
    }

    printf("The queue is empty? %s.\n\n", IsEmpty(queue) ? "yes" : "no");

    getchar();
    return 0;
}
