#include <stdio.h>

#define SIZE 100

void Insertion_Sort(double arr[], int n);

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

    Insertion_Sort(arr, n);

    printf("\n");
    printf("The sorted data are as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%3d : %9.2lf\n", i + 1, arr[i]);
    }
    getchar();
    return 0;
}

void Insertion_Sort(double arr[], int n)
{
    int i, j;
    double tmp;
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
