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

    Merge_Sort(arr, n);

    printf("\n");
    printf("The sorted data are as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%3d : %9.2lf\n", i + 1, arr[i]);
    }
    getchar();
    return 0;
}

void Merge(item_t arr[], item_t tmpArr[], int left, int mid, int right)
{
    int tmp = left;
    int start = left, end = right;
    int leftEnd = mid - 1;

    while (left <= leftEnd && mid <= right)
    {
        if (arr[left] <= arr[mid])
        {
            tmpArr[tmp++] = arr[left++];
        }
        else
        {
            tmpArr[tmp++] = arr[mid++];
        }
    }

    while (left <= leftEnd)
    {
        tmpArr[tmp++] = arr[left++];
    }
    while (mid <= right)
    {
        tmpArr[tmp++] = arr[mid++];
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = tmpArr[i];
    }
}

void Merge_Pass(item_t arr[], item_t tmpArr[], int n, int length)
{
    int i;

    for (i = 0; i <= n - 2 * length; i += 2 * length)
    {
        Merge(arr, tmpArr, i, i + length, i + 2 * length - 1);
    }

    if (i + length < n)
    {
        Merge(arr, tmpArr, i, i + length, n - 1);
    }
    else
    {
        for (int j = i; j < n; j++)
        {
            tmpArr[j] = arr[j];
        }
    }
}

void Merge_Sort(item_t arr[], int n)
{
    int length = 1;
    item_t *tmpArr = malloc(n * sizeof(item_t));
    if (tmpArr != NULL)
    {
        while (length < n)
        {
            Merge_Pass(arr, tmpArr, n, length);
            length *= 2;
            Merge_Pass(tmpArr, arr, n, length);
            length *= 2;
        }
        free(tmpArr);
    }
    else
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }
}
