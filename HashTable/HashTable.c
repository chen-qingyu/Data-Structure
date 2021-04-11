#include "HashTable.h"

int Hash(key_t key)
{
    unsigned int index = 0;

    while (*key != '\0')
    {
        index = (index << 5) + *key++;
    }

    return index % HASH_CAPACITY;
}

table_t CreateTable(void)
{
    table_t table = (table_t)malloc(sizeof(struct item) * HASH_CAPACITY);
    if (table == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    for (int i = 0; i < HASH_CAPACITY; i++)
    {
        table[i].state = EMPTY;
    }

    return table;
}

void DestroyTable(table_t table)
{
    if (table)
    {
        free(table);
        table = NULL;
    }
}

int FindPos(table_t table, key_t key)
{
    int currentPos, newPos;
    int conflictCnt = 0;

    currentPos = Hash(key);
    newPos = currentPos;

    while (table[newPos].state != EMPTY && strcmp(table[newPos].key, key) != 0)
    {
        if (++conflictCnt % 2)
        {
            newPos = currentPos + (conflictCnt + 1) * (conflictCnt + 1) / 4;
            if (newPos >= HASH_CAPACITY)
            {
                newPos = newPos % HASH_CAPACITY;
            }
        }
        else
        {
            newPos = currentPos - conflictCnt * conflictCnt / 4;
            while (newPos < 0)
            {
                newPos += HASH_CAPACITY;
            }
        }
    }

    return newPos;
}

value_t Get(table_t table, key_t key)
{
    int pos = FindPos(table, key);

    if (table[pos].state == FULL)
    {
        return table[pos].value;
    }
    else
    {
        return ERROR;
    }
}

void Modify(table_t table, key_t key, value_t value)
{
    int pos = FindPos(table, key);

    if (table[pos].state == FULL)
    {
        table[pos].value = value;
    }
    else
    {
        fprintf(stderr, "Key-value pair does not exist.\n");
    }
}

void Insert(table_t table, key_t key, value_t value)
{
    int pos = FindPos(table, key);

    if (table[pos].state != FULL)
    {
        table[pos].state = FULL;
        strcpy(table[pos].key, key);
        table[pos].value = value;
    }
    else
    {
        fprintf(stderr, "Key-value pair already exists.\n");
    }
}

void Delete(table_t table, key_t key)
{
    int pos = FindPos(table, key);

    if (table[pos].state == FULL)
    {
        table[pos].state = DELETED;
    }
    else
    {
        fprintf(stderr, "Key-value pair does not exist.\n");
    }
}
