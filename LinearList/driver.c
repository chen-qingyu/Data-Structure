#include "LinearList.h"

int main(int argc, char const *argv[])
{
    list_t list1 = CreateList();
    printf("List 1 length is: %d\n", GetLength(list1));
    Insert(0, 0, list1);
    Insert(1, 1, list1);
    Insert(2, 2, list1);
    Insert(3, 3, list1);
    printf("List 1 length is: %d\n", GetLength(list1));

    printf("\n");

    list_t list2 = CreateList();
    printf("List 2 length is: %d\n", GetLength(list2));
    Insert(233, 0, list2);
    Insert(666, 1, list2);
    Insert(888, 2, list2);
    Insert(999, 3, list2);
    printf("List 2 length is: %d\n", GetLength(list2));

    printf("\n");

    LinkList(list1, list2);
    Print(list1);

    getchar();
    return 0;
}
