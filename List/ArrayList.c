#include "List.h"

struct list
{
    item_t data[LIST_CAPACITY];
    int last;
};

/*******************************
Helper functions implementation.
*******************************/

/*******************************
Interface functions implementation.
*******************************/

list_t CreateList(void)
{
    list_t list = (list_t)malloc(sizeof(struct list));
    if (list == NULL)
    {
        fprintf(stderr, "ERROR: (file %s, line %d) There was not enough memory.\n", __FILE__, __LINE__);
        exit(-2);
    }

    list->last = -1;

    return list;
}

void DestroyList(list_t list)
{
    if (list)
    {
        free(list);
        list = NULL;
    }
}

int GetLength(const list_t list)
{
    return list->last + 1;
}

bool IsFull(const list_t list)
{
    return GetLength(list) >= LIST_CAPACITY;
}

bool IsEmpty(const list_t list)
{
    return GetLength(list) <= 0;
}

item_t Get(const list_t list, int i) // list[i]
{
    if (i < 0 || i > list->last)
    {
        fprintf(stderr, "Illegal location.\n");
        return ERROR;
    }

    return list->data[i];
}

int Find(const list_t list, item_t data)
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

void Insert(list_t list, int i, item_t data)
{
    if (IsFull(list))
    {
        fprintf(stderr, "The list is full.\n");
        return;
    }

    if (i < 0 || i > (list->last + 1))
    {
        fprintf(stderr, "Illegal location.\n");
        return;
    }

    for (int j = list->last; j >= i; j--)
    {
        list->data[j + 1] = list->data[j];
    }
    list->data[i] = data;
    list->last++;
}

void Delete(list_t list, int i)
{
    if (IsEmpty(list))
    {
        fprintf(stderr, "The list is empty.\n");
        return;
    }

    if (i < 0 || i > list->last)
    {
        fprintf(stderr, "Illegal location.\n");
        return;
    }

    for (int j = i + 1; j <= list->last; j++)
    {
        list->data[j - 1] = list->data[j];
    }
    list->last--;
}

void Print(const list_t list)
{
    printf("Now print the list elements:\n");
    for (int i = 0; i < GetLength(list); i++)
    {
        printf("[%d]: %d\n", i, list->data[i]);
    }
    printf("That's all.\n");
}

void Reverse(list_t list)
{
    if (GetLength(list) <= 1)
    {
        return;
    }

    int i = 0;
    int j = list->last; // >= 1

    while (i < j)
    {
        item_t tmp = list->data[i];
        list->data[i] = list->data[j];
        list->data[j] = tmp;
        ++i;
        --j;
    }
}