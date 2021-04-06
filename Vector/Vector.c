#include "Vector.h"

#define ERROR (-1)

#define SIZE 100

struct vector
{
    item_t data[SIZE];
    int last;
};

vector_t CreateVector(void)
{
    vector_t vector = (vector_t)malloc(sizeof(struct vector));
    if (vector == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    vector->last = -1;

    return vector;
}

void DestroyVector(vector_t vector)
{
    if (vector)
    {
        free(vector);
        vector = NULL;
    }
}

int GetLength(vector_t vector)
{
    return vector->last + 1;
}

bool IsFull(vector_t vector)
{
    return GetLength(vector) >= SIZE;
}

bool IsEmpty(vector_t vector)
{
    return GetLength(vector) <= 0;
}

item_t Get(vector_t vector, int i)
{
    if (i < 0 || i > vector->last)
    {
        fprintf(stderr, "Illegal location.\n");
        return ERROR;
    }

    return vector->data[i];
}

int Find(vector_t vector, item_t data)
{
    int index = 0;

    while (index <= vector->last && vector->data[index] != data)
    {
        index++;
    }

    if (index > vector->last)
    {
        return ERROR;
    }
    else
    {
        return index;
    }
}

void Insert(vector_t vector, int i, item_t data)
{
    if (IsFull(vector))
    {
        fprintf(stderr, "The vector is full.\n");
        return;
    }

    if (i < 0 || i > (vector->last + 1))
    {
        fprintf(stderr, "Illegal location.\n");
        return;
    }

    for (int j = vector->last; j >= i; j--)
    {
        vector->data[j + 1] = vector->data[j];
    }
    vector->data[i] = data;
    vector->last++;
}

void Delete(vector_t vector, int i)
{
    if (IsEmpty(vector))
    {
        fprintf(stderr, "The vector is empty.\n");
        return;
    }

    if (i < 0 || i > vector->last)
    {
        fprintf(stderr, "Illegal location.\n");
        return;
    }

    for (int j = i + 1; j <= vector->last; j++)
    {
        vector->data[j - 1] = vector->data[j];
    }
    vector->last--;
}

void Print(vector_t vector)
{
    printf("Now print the vector elements:\n");
    for (int i = 0; i < GetLength(vector); i++)
    {
        printf("%d: %d\n", i, vector->data[i]);
    }
    printf("That's all.\n");
}
