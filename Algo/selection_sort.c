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
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int find_minimum(int *arr, int i, int n) {
    int j, min_idx = i;
      for (j = i + 1; j < n; j++) {
         if (arr[min_idx] > arr[j])
            min_idx = j;
      }
    return min_idx;
}
         
void selectionSort(int *arr, int n)
{
    int i, min_idx;
  
    for (i = 0; i < n-1; i++)
    {
		min_idx = find_minimum(arr, i, n);
		if (min_idx != i)
        	swap(&arr[min_idx], &arr[i]);
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
    int arr[100],n;
    printf("Enter number of elements\n> ");
	scanf("%d", &n);
	inputArr(arr, n);
	printf("\n---------[Process]---------\n");
    selectionSort(arr, n);
    printf("\n---------[Sorted array]---------\n");
    printArr(arr, n);
    return 0;
}
