#include "List.h"

int main(void)
{
    list_t list1 = CreateList(), list2 = CreateList();
    item_t a[] = {1, 2, 3, 4}, b[] = {233, 666, 888, 999};

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        Insert(list1, i, a[i]);
        printf("Insert an item to list 1 [%d]: %d.\n", i, a[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
    {
        Insert(list2, i, b[i]);
        printf("Insert an item to list 2 [%d]: %d.\n", i, b[i]);
    }
    printf("\n");

    printf("Reverse list 1.\n");
    Reverse(list1);
    Print(list1);
    printf("\n");

    for (int i = 0; i < GetLength(list2); ++i)
    {
        Insert(list1, i, Get(list2, i));
        printf("Insert an item from list 2 to list 1 [%d]: %d.\n", i, Get(list2, i));
    }
    printf("\n");
    Print(list1);
    printf("\n");

    item_t elem = 999;
    printf("Find item in list 1: item %d at [%d].\n", elem, Find(list1, elem));
    printf("\n");

    int length = GetLength(list1);
    for (int i = 0; i < length; i++)
    {
        Delete(list1, 0);
        printf("Delete an item from list 1.\n");
    }
    printf("Is list 1 empty? %s.\n", IsEmpty(list1) ? "yes" : "no");
    printf("\n");

    DestroyList(list1);
    DestroyList(list2);
    printf("Destroy all lists.\n");

    return 0;
}
