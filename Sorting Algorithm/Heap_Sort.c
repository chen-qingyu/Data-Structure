#include "Sort.h"

int main(void)
{
    double arr[SIZE];
    int n = 0;
    printf("Please enter the data to be sorted:\n");
    while (scanf("%lf", &arr[n]) && n < SIZE)
    {
        n++;
        if (getchar() == '\n')
        {
            break;
        }
    }

    Heap_Sort(arr, n);

    printf("\n");
    printf("The sorted data are as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%3d : %9.2lf\n", i + 1, arr[i]);
    }
    getchar();
    return 0;
}

void PercDown(double arr[], int r, int n)
{
    /* 将n个元素的数组中以arr[r]为根的子堆调整为最大堆 */
    int parent, child;
    double tmp;

    tmp = arr[r];
    for (parent = r; (parent * 2 + 1) < n; parent = child)
    {
        child = parent * 2 + 1;
        if ((child != n - 1) && (arr[child] < arr[child + 1]))
        {
            child++;
        }
        if (tmp >= arr[child])
        {
            break;
        }
        else
        {
            arr[parent] = arr[child];
        }
    }
    arr[parent] = tmp;
}

void Heap_Sort(double arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        PercDown(arr, i, n);
    }

    for (int i = n - 1; i > 0; i--)
    {
        double tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        PercDown(arr, 0, i);
    }
}
