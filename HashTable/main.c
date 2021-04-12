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

    value_t a = Get(table, "aaa");
    printf("\"aaa\": %d\n", a);
    value_t b = Get(table, "bbb");
    printf("\"bbb\": %d\n", b);
    value_t c = Get(table, "ccc");
    printf("\"ccc\": %d\n", c);
    value_t d = Get(table, "ddd");
    printf("\"ddd\": %d\n", d);
    printf("\n");

    Modify(table, "aaa", 233);
    printf("Modified: \"aaa\": %d\n", Get(table, "aaa"));
    printf("\n");

    Delete(table, "aaa");
    printf("Delete \"aaa\".\n");
    a = Get(table, "aaa");
    if (a == ERROR)
    {
        printf("Deleted successful.\n");
    }
    else
    {
        printf("Deleted failed.\n");
    }
    printf("\n");

    printf("Destroy table...\n");
    DestroyTable(table);

    return 0;
}
