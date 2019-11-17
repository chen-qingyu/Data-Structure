/*
线性表(Linear List)
链表实现
对象集：n(n>=0)个元素构成的有序序列 a1, a2, a3 ... an
操作集：线性表 list 属于 list_t ，整数 i 表示元素下标(从0开始)，元素 x 属于 element_t ，基本操作有：
    1. list_t CreateList(void)
    2. list_t FindByIndex(int i, list_t list)
    3. list_t Find(element_t x, list_t list)
    4. bool Insert(element_t x, int i, list_t list)
    5. bool Delete(int i, list_t list)
    6. int GetLength(list_t list)
    7. void Print(list_t list)
    8. bool LinkList(list_t list1, list_t list2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

typedef int element_t;
typedef struct node * list_t;
struct node
{
    element_t data;
    list_t next;
};

list_t CreateList(void);
list_t FindByIndex(int i, list_t list);
list_t Find(element_t x, list_t list);
bool Insert(element_t x, int i, list_t list);
bool Delete(int i, list_t list);
int GetLength(list_t list);
void Print(list_t list);
bool LinkList(list_t list1, list_t list2);

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

list_t CreateList(void)
{
    list_t list = (list_t)malloc(sizeof(struct node));
    if (list == NULL)
    {
        fprintf(stderr, "Failed to create new list.\n");
        exit(-2);
    }

    list->data = 0; // length
    list->next = NULL;
    printf("Create a new list successful.\n");
    return list;
}

list_t FindByIndex(int i, list_t list)
{
    if (i < 0 || i > (GetLength(list) - 1))
    {
        printf("Illegal location.\n");
        return NULL;
    }

    list_t node = list->next;
    int j = 0;
    while (node != NULL && j < i)
    {
        node = node->next;
        j++;
    }
    return node;
}

list_t Find(element_t x, list_t list)
{
    list_t node = list->next;
    while (node != NULL && node->data != x)
    {
        node = node->next;
    }
    return node;
}

bool Insert(element_t x, int i, list_t list)
{
    if (i < 0 || i > GetLength(list))
    {
        printf("Illegal location.\n");
        return false;
    }

    list_t new = (list_t)malloc(sizeof(struct node));
    if (new == NULL)
    {
        fprintf(stderr, "Failed to create new node.\n");
        exit(-2);
    }

    list_t tmp = list;
    for (int j = 0; j < i; j++)
    {
        tmp = tmp->next;
    }
    new->data = x;
    new->next = tmp->next;
    tmp->next = new;
    list->data++;
    printf("Insert element %d at list[%d] successful.\n", x, i);
    return true;
}

bool Delete(int i, list_t list)
{
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
    list->data--;
    printf("Delete element at list[%d] successful.\n", i);
    return true;
}

int GetLength(list_t list)
{
    // list_t tmp = list->next;
    // int length = 0;
    // while (tmp)
    // {
    //     tmp = tmp->next;
    //     length++;
    // }
    // return length;
    return (int)list->data;
}

void Print(list_t list)
{
    printf("Now print the list elements:\n");
    list_t tmp = list->next;
    for (int i = 0; i < list->data; i++)
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
        list1->data += list2->data;
        free(list2);
        list2 = NULL;
        printf("Link list 1 and list 2 successful.\n");
    }
    return true;
}
