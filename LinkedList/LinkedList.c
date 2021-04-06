#include "LinkedList.h"

#define ERROR (-1)

#define SIZE 100

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

    return list;
}

void DestroyList(list_t list)
{
    if (list)
    {
        list_t current;

        while (list)
        {
            current = list->next;
            free(list);
            list = current;
        }
    }
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

item_t Get(list_t list, int i) // list[i]
{
    if (i < 0 || i > (GetLength(list) - 1))
    {
        fprintf(stderr, "Illegal location.\n");
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

int Find(list_t list, item_t data)
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

void Insert(list_t list, int i, item_t data)
{
    if (IsFull(list))
    {
        fprintf(stderr, "The list is full.\n");
        return;
    }

    if (i < 0 || i > GetLength(list))
    {
        fprintf(stderr, "Illegal location.\n");
        return;
    }

    list_t new = (list_t)malloc(sizeof(struct list));
    if (new == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }
    new->data = data;

    list_t tmp = list;
    for (int j = 0; j < i; j++)
    {
        tmp = tmp->next;
    }
    new->next = tmp->next;
    tmp->next = new;
}

void Delete(list_t list, int i)
{
    if (IsEmpty(list))
    {
        fprintf(stderr, "The list is empty.\n");
        return;
    }

    if (i < 0 || i > (GetLength(list) - 1))
    {
        fprintf(stderr, "Illegal location.\n");
        return;
    }

    list_t tmp = list;
    for (int j = 0; j < i; j++)
    {
        tmp = tmp->next;
    }
    list_t del = tmp->next;
    tmp->next = del->next;
    free(del);
    del = NULL;
}

void Print(list_t list)
{
    printf("Now print the list elements:\n");
    list_t tmp = list->next;
    int len = GetLength(list);
    for (int i = 0; i < len; i++)
    {
        printf("%d: %d\n", i, tmp->data);
        tmp = tmp->next;
    }
    printf("That's all.\n");
}

void LinkList(list_t list1, list_t list2)
{
    if (list1 == list2)
    {
        while (list1->next != NULL)
        {
            list1 = list1->next;
        }
        list1->next = list2->next;
        return;
    }

    list_t tail = list1;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = list2->next;
    free(list2);
    list2 = NULL;
}

void Reverse(list_t list)
{
    if (GetLength(list) == 0)
    {
        return;
    }

    list_t pre = list->next;
    list->next = NULL;
    list_t tmp;

    while (pre)
    {
        tmp = pre;
        pre = pre->next;
        tmp->next = list->next;
        list->next = tmp;
    }
}
