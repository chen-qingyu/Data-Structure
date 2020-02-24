#include "Sort.h"

/*
关于这个快速排序算法的几点，我需要说明一下：
1. 我这里参考了中国大学MOOC浙大的陈越老师的课程设置了一个快排阈值 CUTOFF ，当待排序的元素数量大于这个阈值时才进入快排，否则调用简单排序（这里我用的选择排序，冒泡排序也可以）。因为快速排序会频繁递归，当待排序的元素数量充分小时，快速排序可能还不如简单排序快。
2. 一般来说，快排的参数都有三个：待排序的元素首地址、左边起始下标、右边结束下标，网上的快排程序大多都是这样的。这里我把它简化到了两个参数：待排序的元素首地址、待排序的元素个数。因为快排会频繁地递归，所以原始版本会push push push…… pop pop pop……，这个版本就是push push…… pop pop……，总的来说，就是减少了大概三分之一的函数调用开销。我一开始以为会增加程序的复杂度，降低可读性，但是写完之后发现似乎并没有降低可读性，如果懂了快排的话那么这个程序应该还是很容易看懂的。并且这样刚好符合 void XXX_Sort(item_t arr[], int n) 这样的函数接口，就不用再重新写一个符合接口的函数然后再调用递归了。
*/

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

item_t median(item_t arr[], int n)
{
    int left = 0, right = n - 1;
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

void Quick_Sort(item_t arr[], int n)
{
    if (n > CUTOFF)
    {
        int pivot, low, high;

        pivot = median(arr, n);
        low = 0;
        high = n - 2;

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

        swap(&arr[low], &arr[n - 2]);

        Quick_Sort(arr, low);
        Quick_Sort(arr + low + 1, n - low - 1);
    }
    else
    {
        Insertion_Sort(arr, n);
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
