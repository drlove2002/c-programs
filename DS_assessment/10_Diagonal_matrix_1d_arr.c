//10_Diagonal_matrix_1d_arr
#include <stdio.h>
#define MAX 10

void printArr(int *arr, int size)
{
    int i, j = 1;
    for (i = 0; i < size * size; i++)
    {
        printf("%d ", arr[i]);
        if (i == (size * j) - 1)
        {
            printf("\n");
            j++;
        }
    }
}

void inputArr(int *arr, int size)
{
    int i;
    for (i = 0; i < size * size; i++)
        arr[i] = 0;
    printf("Enter %d integers\n> ", size);
    for (i = 0; i < size; i++)
        scanf("%d", &arr[(size + 1) * i]);
}

int main()
{
    int arr[MAX * MAX], size;
    printf("Matrix size [NxN] enter the value of N:\n> ");
    scanf("%d", &size);
    if (size > 10)
    {
        printf("[Error] Max matrix size allowed is %d", MAX);
    }
    inputArr(arr, size);
    printArr(arr, size);
    return 0;
}