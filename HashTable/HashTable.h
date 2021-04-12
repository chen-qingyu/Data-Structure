/*
散列表(Hash Table)
对象集：散列表是由n(n>=0)个键值对(key-value pair)构成的集合
操作集：散列表 table 属于 table_t ，键 key 属于 key_t ，值 value 属于 value_t ，基本操作有：
    1. table_t CreateTable(void)
    2. void DestroyTable(table_t table)
    3. value_t Get(const table_t table, key_t key)
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

#define HASH_CAPACITY 17

typedef char *key_t;

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

/*************************************************
  Description:    创建一个空散列表
  Parameter:      空
  Return:         一个指向空散列表的指针
*************************************************/
table_t CreateTable(void);

/*************************************************
  Description:    销毁一个散列表 table
  Parameter:      一个指向待销毁散列表的指针 table
  Return:         空
*************************************************/
void DestroyTable(table_t table);

/*************************************************
  Description:    在散列表 table 中取 key 对应的 value
  Parameter:      一个指向散列表的指针 table
                  一个 key
  Return:         key 对应的 value 或者 ERROR
*************************************************/
value_t Get(const table_t table, key_t key);

/*************************************************
  Description:    在散列表 table 中修改 key 对应的 value
  Parameter:      一个指向散列表的指针 table
                  一个 key
                  一个新的 value
  Return:         空
*************************************************/
void Modify(table_t table, key_t key, value_t value);

/*************************************************
  Description:    在散列表 table 中插入一个新的键值对
  Parameter:      一个指向散列表的指针 table
                  一对新的 key 和 value
  Return:         空
*************************************************/
void Insert(table_t table, key_t key, value_t value);

/*************************************************
  Description:    在散列表 table 中删除 key 对应的键值对
  Parameter:      一个指向散列表的指针 table
                  待删除键值对的 key
  Return:         空
*************************************************/
void Delete(table_t table, key_t key);

#endif
