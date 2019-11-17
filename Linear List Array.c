/*
线性表(Linear List)
数组实现
对象集：n(n>=0)个元素构成的有序序列 a1, a2, a3 ... an
操作集：线性表 list 属于 list_t ，整数 i 表示元素下标(从0开始)，元素 x 属于 element_t ，基本操作有：
    1. list_t CreateList(void)
    2. element_t FindByIndex(int i, list_t list)
    3. int Find(element_t x, list_t list)
    4. bool Insert(element_t x, int i, list_t list)
    5. bool Delete(int i, list_t list)
    6. int GetLength(list_t list)
    7. void Print(list_t list)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define SIZE 100
#define ERROR (-1)

typedef int element_t;
typedef struct node * list_t;
struct node
{
    element_t data[SIZE];
    int last;
};

list_t CreateList(void);
element_t FindByIndex(int i, list_t list);
int Find(element_t x, list_t list);
bool Insert(element_t x, int i, list_t list);
bool Delete(int i, list_t list);
int GetLength(list_t list);
void Print(list_t list);

int main(int argc, char const *argv[])
{
    list_t list = CreateList();
    printf("List length is: %d\n", GetLength(list));
    Insert(0, 0, list);
    Insert(1, 1, list);
    Insert(2, 2, list);
    Insert(3, 3, list);
    printf("List length is: %d\n", GetLength(list));
    Print(list);
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

    list->last = -1;
    printf("Create a new list successful.\n");
    return list;
}

element_t FindByIndex(int i, list_t list)
{
    if (i < 0 || i > list->last)
    {
        printf("Illegal location.\n");
        return ERROR;
    }

    return list->data[i];
}

int Find(element_t x, list_t list)
{
    int i = 0;
    while (i <= list->last && list->data[i] != x)
    {
        i++;
    }
    if (i > list->last)
    {
        return ERROR;
    }
    else
    {
        return i;
    }
}

bool Insert(element_t x, int i, list_t list)
{
    if (list->last == (SIZE - 1))
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
    list->data[i] = x;
    list->last++;
    printf("Insert element %d at list[%d] successful.\n", x, i);
    return true;
}

bool Delete(int i, list_t list)
{
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
    printf("Delete element at list[%d] successful.\n", i);
    return true;
}

int GetLength(list_t list)
{
    return list->last + 1;
}

void Print(list_t list)
{
    printf("Now print the list elements:\n");
    for (int i = 0; i <= list->last; i++)
    {
        printf("list[%d]: %d\n", i, list->data[i]);
    }
    printf("That's all.\n");
}
