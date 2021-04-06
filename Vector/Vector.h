/*
向量(Vector)
对象集：n(n>=0)个元素构成的有序序列 a1, a2, a3 ... an.
操作集：向量 vector 属于 vector_t ，整数 i 表示元素下标(从0开始)，元素 data 属于 item_t ，基本操作有：
    1. vector_t CreateVector(void)
    2. void DestroyVector(vector_t vector)
    3. int GetLength(vector_t vector)
    4. bool IsFull(vector_t vector)
    5. bool IsEmpty(vector_t vector)
    6. item_t Get(vector_t vector, int i)
    7. int Find(vector_t vector, item_t data)
    8. void Insert(vector_t vector, int i, item_t data)
    9. void Delete(vector_t vector, int i)
    10. void Print(vector_t vector)
*/

#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int item_t;

typedef struct vector *vector_t;

vector_t CreateVector(void);
void DestroyVector(vector_t vector);
int GetLength(vector_t vector);
bool IsFull(vector_t vector);
bool IsEmpty(vector_t vector);
item_t Get(vector_t vector, int i);
int Find(vector_t vector, item_t data);
void Insert(vector_t vector, int i, item_t data);
void Delete(vector_t vector, int i);
void Print(vector_t vector);

#endif
