#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, k, a[10][10], b[10][10], c[10][10], row1, col1, row2, col2, row3, col3;
    printf("\nEnter the row and column of the first matrix: ");
    scanf("%d%d", &row1, &col1);
    printf("\nEnter the row and column of the second matrix: ");
    scanf("%d%d", &row2, &col2);
    if (col1 != row2)
    {
        printf("\nWrong Dimension! Multiplication is not possible");
        exit(1);
    }
    printf("\nEnter the elements of first matrix (row wise):\n");
    for (i = 0; i < row1; i++)
        for (j = 0; j < col1; j++)
            scanf("%d", &a[i][j]);
    printf("\nEnter the elements of second matrix (row wise):\n");
    for (i = 0; i < row2; i++)
        for (j = 0; j < col2; j++)
            scanf("%d", &b[i][j]);
    printf("\nThe elements of first matrix are\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    printf("\nThe elements of second matrix are\n");
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
            printf("%d\t", b[i][j]);
        printf("\n");
    }
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < row2; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    row3 = row1;
    col3 = col2;
    printf("\nThe elements of result matrix are\n");
    for (i = 0; i < row3; i++)
    {
        for (j = 0; j < col3; j++)
            printf("%d\t", c[i][j]);
        printf("\n");
    }
}