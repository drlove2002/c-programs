#include <stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main()
{
    int arr[10][10], i, j, row, col, temp;
    printf("Enter the number of Rows:");
    scanf("%d", &row);
    printf("Enter the number of Columns:");
    scanf("%d", &col);

    //check if row or column is more more than 10
    if (row > 10 || col > 10)
    {
        printf("Wrong input");
        exit(1);
    }

    //input matrix elements
    printf("Enter the elements of the matrix:\n> ");
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &arr[i][j]);

    //print the original matrix
    printf("Entered matrix is:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }

    if (row > col)
        temp = row;
    else
        temp = col;

    for (i = 0; i < temp; i++) //swap eliments
        for (j = i; j < temp; j++)
        {
            if (i != j)
                swap(&arr[i][j], &arr[j][i]);
        }

    if (row != col)
        swap(&row, &col);

    //print the transposed matrix
    printf("The transpose matrix is:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
    return 0;
}