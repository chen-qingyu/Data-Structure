#include "HashTable.h"

int main(void)
{
    table_t table = CreateTable();

    printf("Insert 4 items.\n");
    Insert(table, "aaa", 1);
    Insert(table, "bbb", 2);
    Insert(table, "ccc", 3);
    Insert(table, "ddd", 4);
    printf("Inserted.\n\n");

    int a = Find(table, "aaa");
    printf("[%2d] %s: %d\n", a, table[a].key, table[a].value);
    int b = Find(table, "bbb");
    printf("[%2d] %s: %d\n", b, table[b].key, table[b].value);
    int c = Find(table, "ccc");
    printf("[%2d] %s: %d\n", c, table[c].key, table[c].value);
    int d = Find(table, "ddd");
    printf("[%2d] %s: %d\n", d, table[d].key, table[d].value);
    printf("\n");

    Modify(table, "aaa", 233);
    printf("Modified: %s: %d\n", table[a].key, table[a].value);
    printf("\n");

    Delete(table, "aaa");
    printf("Delete \"aaa\".\n");
    a = Find(table, "aaa");
    if (a == ERROR)
    {
        printf("Deleted successful.\n");
    }
    else
    {
        printf("Deleted failed.\n");
    }
    printf("\n");

    printf("Destroy table.\n");
    DestroyTable(table);

    return 0;
}
