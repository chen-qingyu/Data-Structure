#include "Sort.h"

int main(void)
{
    item_t arr[SIZE];
    int n = 0;
    printf("Please input the data to be sorted:\n");
    while (n < SIZE && scanf("%lf", &arr[n]))
    {
        n++;
        if (getchar() == '\n')
        {
            break;
        }
    }

    Radix_Sort(arr, n);

    printf("\n");
    printf("The sorted data are as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%3d : %9.2lf\n", i + 1, arr[i]);
    }
    getchar();
    return 0;
}

typedef struct node *node_t;
struct node
{
    item_t key;
    node_t next;
};

struct headNode
{
    node_t head, tail;
};
typedef struct headNode bucket_t[RADIX];

int GetDigit(item_t item, int D)
{
    int digit;

    for (int i = 1; i <= D; i++)
    {
        digit = (int)item % RADIX;
        item /= RADIX;
    }
    return digit;
}

void Radix_Sort(item_t arr[], int n)
{
    int negativeFlag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            negativeFlag = 1;
            break;
        }
    }

    if (negativeFlag)
    {
        Insertion_Sort(arr, n);
    }
    else
    {
        int D, digit;
        bucket_t bucket;
        node_t tmp, p, list = NULL;

        for (int i = 0; i < RADIX; i++)
        {
            bucket[i].head = NULL;
            bucket[i].tail = NULL;
        }
        for (int i = 0; i < n; i++)
        {
            tmp = (node_t)malloc(sizeof(struct node));
            tmp->key = arr[i];
            tmp->next = list;
            list = tmp;
        }

        for (D = 1; D <= MAX_DIGIT; D++)
        {
            p = list;
            while (p)
            {
                digit = GetDigit(p->key, D);

                tmp = p;
                p = p->next;
                tmp->next = NULL;

                if (bucket[digit].head == NULL)
                {
                    bucket[digit].head = tmp;
                    bucket[digit].tail = tmp;
                }
                else
                {
                    bucket[digit].tail->next = tmp;
                    bucket[digit].tail = tmp;
                }
            }

            list = NULL;

            for (digit = RADIX - 1; digit >= 0; digit--)
            {
                if (bucket[digit].head)
                {
                    bucket[digit].tail->next = list;
                    list = bucket[digit].head;
                    bucket[digit].head = bucket[digit].tail = NULL;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            tmp = list;
            list = list->next;
            arr[i] = tmp->key;
            free(tmp);
        }
    }
}

void Insertion_Sort(item_t arr[], int n)
{
    int i, j;
    item_t tmp;
    for (i = 1; i < n; i++)
    {
        tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}
