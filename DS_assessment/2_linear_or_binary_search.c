//2_linear_or_binary_search
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

void printArr(int *arr, int size)
{
    int i;
    printf("> ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int linear_search(int *a, int n, int find)
{
    int c;
    for (c = 0; c < n; c++)
    {
        if (a[c] == find)
            return c;
    }
    return -1;
}

int binary_search(int *arr, int n, int item)
{
    int mid, L = 0, U = n - 1;
    while (U >= L)
    {
        mid = (U + L) / 2;
        if (arr[mid] == item)
            return mid;
        else if (arr[mid] > item)
            U = mid - 1;
        else
            L = mid + 1;
    }
    return -1;
}

void inputArr(int *arr, int size)
{
    int i;
    printf("Enter %d integers\n> ", size);
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void input_sorted_arr(int *arr, int size)
{
    int i, flag;
    while (1)
    {
        flag = 1;
        printf("Enter %d elements of the array\nNOTE: Array insertion should be in ascending order\n", size);
        for (i = 0; i < size; i++)
            scanf("%d", &arr[i]);
        for (i = 0; i < size - 1; i++)
            if (arr[i] > arr[i + 1])
            {
                printf("[ERROR!] The array is not in ascending order, Re Enter\n");
                flag = 0;
                break;
            }
        if (flag == 1)
            break;
    }
}

int main()
{
    int i, arr[MAXSIZE], n, flag = 0, item, position, opt;
    //Intup the array lenght
    printf("Enter the lenght of the array:\n> ");
    scanf("%d", &n);
    if (n > 20)
    {
        printf("ERROR!\nArray size must be less than 20!");
        exit(0);
    }

    while (1)
    {
        printf("-----------[MENU]-----------\n");
        printf("1) Binary search\n");
        printf("2) Linear Search\n");
        printf("0) EXIT\n");
        printf("----------------------------\n");

        printf("> Choose an option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            system("cls");
            exit(0);
        case 2:
            printf("Enter %d integers:\n> ", n);
            inputArr(arr, n); //Input the array elements
            printf("all elements of the given array:\n");
            printArr(arr, n);

            //Searching the item
            printf("Enter the element to be searched:\n> ");
            scanf("%d", &item);
            position = linear_search(arr, n, item);
            if (position == -1)
                printf("Item not found in the array!\n");
            else
                printf("[!] %d found in position %d\n", item, position + 1);
            break;
        case 1:
            input_sorted_arr(arr, n);
            printf("all elements of the given array:\n");
            printArr(arr, n);

            //Searching the item
            printf("Enter the element to be searched:\n> ");
            scanf("%d", &item);
            position = binary_search(arr, n, item);
            if (position == -1)
                printf("Item not found in the array!\n");
            else
                printf("[!] %d found in position %d\n", item, position + 1);
            break;
        default:
            printf("[x] Error! Wrong Input");
        }
    }
}