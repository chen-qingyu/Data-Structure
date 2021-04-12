#include "MaxHeap.h"

int main(void)
{
    heap_t heap = CreateHeap();

    printf("Is the heap empty? %s\n", IsEmpty(heap) ? "Yes" : "No");
    printf("\n");

    printf("Insert data: 1, 2, 4, 3.\n");
    Insert(heap, 1);
    Insert(heap, 2);
    Insert(heap, 4);
    Insert(heap, 3);
    printf("\n");

    printf("Is the heap empty? %s\n", IsEmpty(heap) ? "Yes" : "No");
    printf("\n");

    printf("Delete 4 items.\n");
    printf("The data is %d.\n", Delete(heap));
    printf("The data is %d.\n", Delete(heap));
    printf("The data is %d.\n", Delete(heap));
    printf("The data is %d.\n", Delete(heap));
    printf("\n");

    printf("Is the heap empty? %s\n", IsEmpty(heap) ? "Yes" : "No");
    printf("\n");

    DestroyHeap(heap);
    printf("Destroy heap...\n");

    return 0;
}
