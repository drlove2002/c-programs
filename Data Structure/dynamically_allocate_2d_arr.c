/*dynamically allocate a 2d array*/

#include <stdio.h>
#include <stdlib.h>

/*Allocate 2d array dynamically*/
int **setup(int **arr, int row, int col)
{
    int i;
    arr = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < row; i++)
        arr[i] = (int *)malloc(row * sizeof(int));
    return arr;
}

/*input eliments into the 2d array*/
int **input(int **arr, int row, int col)
{
    int i, j, *ptr;
    printf("Enter the eliments: ");
    for (i = 0; i < row; i++)
    {
        ptr = arr[i];
        for (j = 0; j < col; j++)
            scanf("%d", &ptr[j]);
    }
    return arr;
}

/*print 2d array's eliments*/
void print_arr(int **arr, int row, int col)
{
    int i, j, *ptr;
    printf("Eliments are:\n");
    for (i = 0; i < row; i++)
    {
        ptr = arr[i];
        for (j = 0; j < col; j++)
            printf("%d\t", ptr[j]);
        printf("\n");
    }
}

int main()
{
    int row, col, **arr, *ptr, i, j;
    printf("Enter Row and Colomn: ");
    scanf("%d%d", &row, &col); //User intup the row and col

    arr = setup(arr, row, col); //call by value
    arr = input(arr, row, col); //call by value

    // setup(&arr, row, col);   //call by reference
    // input(&arr, row, col);   //call by reference

    print_arr(arr, row, col); //print the array
    return 0;
}