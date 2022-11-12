//6_quick_sort
#include <stdio.h>
int size;

//swap two values
void swap(int *n1, int *n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

//print an array
void printArr(int *arr)
{
    int i;
    printf("> ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//this func is partitioning index to place arr[pi] at right place
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // pivot (Element to be placed at right position)
    int p = low + 1;      // next Element index of low
    int q = high;
    while (p < q)
    {
        while (arr[p] <= pivot)
            p++;
        while (arr[q] > pivot)
            q--;
        if (p < q)
            swap(&arr[p], &arr[q]);
    }
    swap(&arr[low], &arr[q]);
    return q;
}

//quickSort algorithm function
void quickSort(int arr[], int low, int high)
{
    int pi;
    printArr(arr);
    if (low < high)
    {
        pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}

//input eluments to an arrey
void inputArr(int *arr)
{
    int i;
    printf("Enter %d integers\n> ", size);
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

int main()
{
    int arr[100];
    printf("Enter number of elements\n> ");
    scanf("%d", &size);
    inputArr(arr);
    printf("---------[Process]---------\n");
    quickSort(arr, 0, size - 1);
    printf("---------[Sorted array]---------\n");
    printArr(arr);
    return 0;
}
