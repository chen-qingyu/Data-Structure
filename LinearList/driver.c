#include "LinearList.h"

int main(int argc, char const *argv[])
{
    list_t list1 = CreateList(), list2 = CreateList();
    item_t a[] = {1, 2, 3, 4}, b[] = {233, 666, 888, 999};
    printf("\n");

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        if (Insert(list1, i, a[i]))
        {
            printf("Insert an item to list 1: %d.\n", a[i]);
        }
        else
        {
            printf("Failed to insert items.\n");
        }
    }
    printf("\n");

    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
    {
        if (Insert(list2, i, b[i]))
        {
            printf("Insert an item to list 2: %d.\n", b[i]);
        }
        else
        {
            printf("Failed to insert items.\n");
        }
    }
    printf("\n");

    LinkList(list1, list2);
    Print(list1);
    printf("\n");

    int length = GetLength(list1);
    for (int i = 0; i < length; i++)
    {
        printf("Delete an item %s.\n", Delete(list1, 0) ? "successful" : "failed");
    }
    printf("The list is empty? %s.\n", IsEmpty(list1) ? "yes" : "no");

    getchar();
    return 0;
}
