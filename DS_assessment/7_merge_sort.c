//7_merge_sort
#include <stdio.h>

int n;

void printArr(char title[20], int *arr, int start, int end)
{
    int i;
    printf(">%s: ", title);
    for (i = start; i < end + 1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void mergeArr(int *arr, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0, temp[right - left + 1], m;
    while ((i <= mid) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (j <= right)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    printArr("Temp arr", temp, 0, k - 1);
    for (k = 0, m = left; m <= right; m++, k++)
        arr[m] = temp[k];
    printArr("Main arr", arr, 0, n - 1);
    printf("\n");
}

void mergeSort(int *arr, int left, int right)
{
    int mid;
    if (left == right)
        return;
    else
    {
        mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        mergeArr(arr, left, mid, right);
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
    int arr[100];
    printf("Enter number of elements for array\n> ");
    scanf("%d", &n);
    inputArr(arr, n);
    printf("\n----------[Process]----------\n");
    mergeSort(arr, 0, n - 1);
    printf("\n---------[Sorted array]---------\n");
    printArr("Final result", arr, 0, n - 1);
    return 0;
}
