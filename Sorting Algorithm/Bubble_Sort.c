#include <stdio.h>

#define SIZE 100

void Bubble_Sort(double arr[], int n);

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

    Bubble_Sort(arr, n);

    printf("\n");
    printf("The sorted data are as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%3d : %9.2lf\n", i + 1, arr[i]);
    }
    getchar();
    return 0;
}

void Bubble_Sort(double arr[], int n)
{
    int flag;
    double tmp;
    for (int i = 1; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 1; // 标识发生了交换
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}
