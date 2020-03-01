#include "MaxHeap.h"

int main(void)
{
    heap_t heap = CreateHeap();

    printf("Is the heap empty? %s\n", IsEmpty(heap) ? "Yes" : "No");

    printf("Insert data: 1, 2.\n");
    Insert(heap, 1);
    Insert(heap, 2);

    printf("Is the heap empty? %s\n", IsEmpty(heap) ? "Yes" : "No");

    printf("Build heap.\n");
    BuildMaxHeap(heap);

    printf("Delete three times.\n");
    printf("The data is %d.\n", Delete(heap));
    printf("The data is %d.\n", Delete(heap));
    printf("The data is %d.\n", Delete(heap));

    printf("Is the heap empty? %s\n", IsEmpty(heap) ? "Yes" : "No");

    getchar();
    return 0;
}
