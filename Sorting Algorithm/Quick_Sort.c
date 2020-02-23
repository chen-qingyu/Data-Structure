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

    Quick_Sort(arr, n);

    printf("\n");
    printf("The sorted data are as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%3d : %9.2lf\n", i + 1, arr[i]);
    }
    getchar();
    return 0;
}

void swap(item_t *a, item_t *b)
{
    item_t tmp = *a;
    *a = *b;
    *b = tmp;
}

item_t median(item_t arr[], int left, int right)
{
    int center = (left + right) / 2;

    if (arr[left] > arr[center])
    {
        swap(&arr[left], &arr[center]);
    }
    if (arr[left] > arr[right])
    {
        swap(&arr[left], &arr[right]);
    }
    if (arr[center] > arr[right])
    {
        swap(&arr[center], &arr[right]);
    }

    swap(&arr[center], &arr[right - 1]);

    return arr[right - 1];
}

void sort(item_t arr[], int left, int right)
{
    if (right - left >= CUTOFF)
    {
        int pivot, low, high;

        pivot = median(arr, left, right);
        low = left;
        high = right - 1;

        while (1)
        {
            while (arr[++low] < pivot)
                ;
            while (arr[--high] > pivot)
                ;
            if (low < high)
            {
                swap(&arr[low], &arr[high]);
            }
            else
            {
                break;
            }
        }

        swap(&arr[low], &arr[right - 1]);

        sort(arr, left, low - 1);
        sort(arr, low + 1, right);
    }
    else
    {
        Insertion_Sort(arr + left, right - left + 1);
    }
}

void Quick_Sort(item_t arr[], int n)
{
    sort(arr, 0, n - 1);
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
