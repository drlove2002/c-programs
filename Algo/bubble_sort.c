#include <stdio.h>

void swap(int *n1, int *n2)
{
        int temp;
        temp = *n1;
        *n1 = *n2;
        *n2 = temp;
}

void printArr(int *arr, int size)
{
        int i;
        printf("> ");
        for (i = 0; i < size; i++)
                printf("%d ", arr[i]);
        printf("\n");
}

void bubbleSort(int *arr, int n)
{
        int i, j;
        for (i = 0; i < n - 1; i++)
        {
                for (j = 0; j < n - i - 1; j++)
                {
                        if (arr[j] > arr[j + 1])
                                swap(&arr[j], &arr[j + 1]);
                        printArr(arr, n);
                }
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
        bubbleSort(arr, n);
        printf("\n---------[Sorted array]---------\n");
        printArr(arr, n);
        return 0;
}
