#include "LinkedList.h"

int main(void)
{
    list_t list1 = CreateList(), list2 = CreateList();
    item_t a[] = {1, 2, 3, 4}, b[] = {233, 666, 888, 999};

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        Insert(list1, i, a[i]);
        printf("Insert an item to list 1: %d.\n", a[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
    {
        Insert(list2, i, b[i]);
        printf("Insert an item to list 2: %d.\n", b[i]);
    }
    printf("\n");

    LinkList(list1, list2);
    Print(list1);
    printf("\n");

    Reverse(list1);
    Print(list1);
    printf("\n");

    int length = GetLength(list1);
    for (int i = 0; i < length; i++)
    {
        Delete(list1, 0);
        printf("Delete an item.\n");
    }
    printf("The list is empty? %s.\n", IsEmpty(list1) ? "yes" : "no");
    printf("\n");

    DestroyList(list1);
    DestroyList(list2);
    printf("Destroy list.\n");

    return 0;
}
