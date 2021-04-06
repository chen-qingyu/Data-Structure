#include "Vector.h"

int main(void)
{
    vector_t vector1 = CreateVector();
    vector_t vector2 = CreateVector();

    item_t a[] = {1, 2, 3, 4};
    item_t b[] = {233, 666, 888, 999};

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        Insert(vector1, i, a[i]);
        printf("Insert an item to vector 1: %d.\n", a[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
    {
        Insert(vector2, i, b[i]);
        printf("Insert an item to vector 2: %d.\n", b[i]);
    }
    printf("\n");

    int length = GetLength(vector1);
    for (int i = 0; i < length; i++)
    {
        Delete(vector1, 0);
        printf("Delete an item.\n");
    }
    printf("The vector is empty? %s.\n", IsEmpty(vector1) ? "yes" : "no");
    printf("\n");

    DestroyVector(vector1);
    DestroyVector(vector2);
    printf("Destroy vector.\n");

    return 0;
}
