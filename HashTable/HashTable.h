/*
散列表(Hash Table)
对象集：散列表是由n(n>=0)个键值对(key-value pair)构成的集合
操作集：散列表 table 属于 table_t ，键 key 属于 key_t ，值 value 属于 value_t ，基本操作有：
    1. table_t CreateTable(void)
    2. void DestroyTable(table_t table)
    3. int Find(table_t table, key_t key)
    4. void Modify(table_t table, key_t key, value_t value)
    5. void Insert(table_t table, key_t key, value_t value)
    6. void Delete(table_t table, key_t key)
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR (-1)

#define SIZE 17
#define MAX_KEY_SIZE 10

typedef char key_t[MAX_KEY_SIZE];

typedef int value_t;

typedef enum
{
    EMPTY,
    FULL,
    DELETED
} state_t;

struct item
{
    key_t key;
    value_t value;
    state_t state;
};

typedef struct item *table_t;

table_t CreateTable(void);
void DestroyTable(table_t table);
int Find(table_t table, key_t key);
void Modify(table_t table, key_t key, value_t value);
void Insert(table_t table, key_t key, value_t value);
void Delete(table_t table, key_t key);

#endif
