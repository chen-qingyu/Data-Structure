#include <stdio.h>

void Quick_Sort(double arr[], int left, int right);

int main(void)
{
    double arr[100];
    int n = 0;
    printf("Please enter the data to be sorted:\n");
    while (scanf("%lf", &arr[n]) && ++n)
        if (getchar() == '\n')
            break;

    Quick_Sort(arr, 0, n - 1);

    printf("\nThe sorted data are as follows:\n");
    for (int i = 0; i < n; i++)
        printf("%3d : %9.2lf\n", i + 1, arr[i]);
    getchar();
    return 0;
}

void Quick_Sort(double arr[], int left, int right)
{
    if (left < right)
    {
        int i = left, j = right;
        double tmp = arr[left];
        while (i < j)
        {
            while (i < j && arr[j] >= tmp)
                j--;
            if (i < j)
                arr[i++] = arr[j];
            while (i < j && arr[i] <= tmp)
                i++;
            if (i < j)
                arr[j--] = arr[i];
        }
        arr[i] = tmp;
        Quick_Sort(arr, left, i - 1);
        Quick_Sort(arr, i + 1, right);
    }
}
