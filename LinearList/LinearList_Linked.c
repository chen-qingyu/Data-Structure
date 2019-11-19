#include "LinearList.h"

struct list
{
    item_t data;
    list_t next;
};

list_t CreateList(void)
{
    list_t list = (list_t)malloc(sizeof(struct list));
    if (list == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    list->next = NULL;
    printf("Create a new list successful.\n");
    return list;
}

int GetLength(list_t list)
{
    list_t current = list->next;
    int length = 0;
    while (current)
    {
        current = current->next;
        length++;
    }
    return length;
}

bool IsFull(list_t list)
{
    return GetLength(list) >= SIZE;
}

bool IsEmpty(list_t list)
{
    return list->next == NULL;
}

item_t FindByIndex(int i, list_t list)
{
    if (i < 0 || i > (GetLength(list) - 1))
    {
        printf("Illegal location.\n");
        return ERROR;
    }

    list_t current = list->next;
    int j = 0;
    while (current != NULL && j < i)
    {
        current = current->next;
        j++;
    }
    if (current)
    {
        return current->data;
    }
    else
    {
        return ERROR;
    }
}

int Find(item_t data, list_t list)
{
    int index = 0;
    list_t current = list->next;
    while (current != NULL && current->data != data)
    {
        current = current->next;
        index++;
    }
    if (current)
    {
        return index;
    }
    else
    {
        return ERROR;
    }
}

bool Insert(item_t data, int i, list_t list)
{
    if (IsFull(list))
    {
        printf("The list is full.\n");
        return false;
    }

    if (i < 0 || i > GetLength(list))
    {
        printf("Illegal location.\n");
        return false;
    }

    list_t new = (list_t)malloc(sizeof(struct list));
    if (new == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    list_t tmp = list;
    for (int j = 0; j < i; j++)
    {
        tmp = tmp->next;
    }
    new->data = data;
    new->next = tmp->next;
    tmp->next = new;
    printf("Insert element %d at list[%d] successful.\n", data, i);
    return true;
}

bool Delete(int i, list_t list)
{
    if (IsEmpty(list))
    {
        printf("The list is empty.\n");
        return false;
    }

    if (i < 0 || i > (GetLength(list) - 1))
    {
        printf("Illegal location.\n");
        return false;
    }

    list_t tmp = list;
    for (int j = 0; j < i; j++)
    {
        tmp = tmp->next;
    }
    list_t del = tmp->next;
    tmp->next = del->next;
    free(del);
    printf("Delete element at list[%d] successful.\n", i);
    return true;
}

void Print(list_t list)
{
    printf("Now print the list elements:\n");
    list_t tmp = list->next;
    for (int i = 0; i < GetLength(list); i++)
    {
        printf("list[%d]: %d\n", i, tmp->data);
        tmp = tmp->next;
    }
    printf("That's all.\n");
}

bool LinkList(list_t list1, list_t list2)
{
    list_t tail = list1;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = list2->next;

    if (list1 == list2)
    {
        printf("Make a circular linked list successful.\n");
    }
    else
    {
        free(list2);
        list2 = NULL;
        printf("Link list 1 and list 2 successful.\n");
    }
    return true;
}
