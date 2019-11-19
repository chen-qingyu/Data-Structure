#include "LinearList.h"

struct list
{
    item_t data[SIZE];
    int last;
};

list_t CreateList(void)
{
    list_t list = (list_t)malloc(sizeof(struct list));
    if (list == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    list->last = -1;
    printf("Create a new list successful.\n");
    return list;
}

int GetLength(list_t list)
{
    return list->last + 1;
}

bool IsFull(list_t list)
{
    return GetLength(list) >= SIZE;
}

bool IsEmpty(list_t list)
{
    return GetLength(list) <= 0;
}

item_t FindByIndex(list_t list, int i)
{
    if (i < 0 || i > list->last)
    {
        printf("Illegal location.\n");
        return ERROR;
    }

    return list->data[i];
}

int Find(list_t list, item_t data)
{
    int index = 0;
    while (index <= list->last && list->data[index] != data)
    {
        index++;
    }
    if (index > list->last)
    {
        return ERROR;
    }
    else
    {
        return index;
    }
}

bool Insert(list_t list, int i, item_t data)
{
    if (IsFull(list))
    {
        printf("The list is full.\n");
        return false;
    }

    if (i < 0 || i > (list->last + 1))
    {
        printf("Illegal location.\n");
        return false;
    }

    for (int j = list->last; j >= i; j--)
    {
        list->data[j + 1] = list->data[j];
    }
    list->data[i] = data;
    list->last++;
    return true;
}

bool Delete(list_t list, int i)
{
    if (IsEmpty(list))
    {
        printf("The list is empty.\n");
        return false;
    }

    if (i < 0 || i > list->last)
    {
        printf("Illegal location.\n");
        return false;
    }

    for (int j = i + 1; j <= list->last; j++)
    {
        list->data[j - 1] = list->data[j];
    }
    list->last--;
    return true;
}

void Print(list_t list)
{
    printf("Now print the list elements:\n");
    for (int i = 0; i < GetLength(list); i++)
    {
        printf("%d: %d\n", i, list->data[i]);
    }
    printf("That's all.\n");
}

bool LinkList(list_t list1, list_t list2)
{
    printf("Array can't implement %s function.\n", __FUNCTION__);
    return false;
}
