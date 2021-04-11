/*
散列表(Hash Table)
对象集：散列表是由n(n>=0)个键值对(key-value pair)构成的集合
操作集：散列表 table 属于 table_t ，键 key 属于 key_t ，值 value 属于 value_t ，基本操作有：
    1. table_t CreateTable(void)
    2. void DestroyTable(table_t table)
    3. value_t Get(table_t table, key_t key)
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

/*************************************************
  Description:    创建一个空散列表
  Input:          空
  Return:         一个指向空散列表的指针
*************************************************/
table_t CreateTable(void);

/*************************************************
  Description:    销毁一个散列表
  Input:          一个指向待销毁散列表的指针
  Return:         空
*************************************************/
void DestroyTable(table_t table);

/*************************************************
  Description:    取key对应的value
  Input:          一个指向散列表的指针， 一个key
  Return:         key对应的value或者ERROR
*************************************************/
value_t Get(table_t table, key_t key);

/*************************************************
  Description:    修改key对应的value
  Input:          一个指向散列表的指针， 一个key，一个新的value
  Return:         空
*************************************************/
void Modify(table_t table, key_t key, value_t value);

/*************************************************
  Description:    插入一个键值对
  Input:          一个指向散列表的指针， 一对新的key和value
  Return:         空
*************************************************/
void Insert(table_t table, key_t key, value_t value);

/*************************************************
  Description:    删除一个键值对
  Input:          一个指向散列表的指针， 待删除键值对的key
  Return:         空
*************************************************/
void Delete(table_t table, key_t key);

#endif
