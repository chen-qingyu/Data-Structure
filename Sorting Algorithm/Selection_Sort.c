#include "Sort.h"

int main(void)
{
    item_t arr[SIZE];
    int n = 0;
    printf("Please input the data to be sorted:\n");
    while (scanf("%lf", &arr[n]) && n < SIZE)
    {
        n++;
        if (getchar() == '\n')
        {
            break;
        }
    }

    Selection_Sort(arr, n);

    printf("\n");
    printf("The sorted data are as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%3d : %9.2lf\n", i + 1, arr[i]);
    }
    getchar();
    return 0;
}

void Selection_Sort(item_t arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minPosition = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minPosition])
            {
                minPosition = j;
            }
        }
        if (minPosition != i)
        {
            item_t tmp = arr[i];
            arr[i] = arr[minPosition];
            arr[minPosition] = tmp;
        }
    }
}
