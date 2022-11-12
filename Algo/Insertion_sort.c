#include <stdio.h>

void printArr(int *arr, int size)
{
    int i;
    printf("> ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int *arr, int n)
{
    int i, j, k, t;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < i; j++)
        {
            t = arr[i + 1];
            if (t < arr[j])
            {
                for (k = i; k >= j; k--)
                    arr[k + 1] = arr[k];
                arr[j] = t;
                break;
            }
        }
        printArr(arr, n);
    }
}

void inputArr(int *arr, int size)
{
    int i;
    printf("Enter %d integers\n> ", size);
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

int main()
{
    int arr[100], n;
    printf("Enter number of elements\n> ");
    scanf("%d", &n);
    inputArr(arr, n);
    printf("\n---------[Process]---------\n");
    insertionSort(arr, n);
    printf("\n---------[Sorted array]---------\n");
    printArr(arr, n);
    return 0;
}
