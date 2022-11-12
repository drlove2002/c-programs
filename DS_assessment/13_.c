#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r[50], c[50], v[50], row, col, i, j, e, p = 0, q = 0;
    printf("\nEnter the number of row: ");
    scanf("%d", &row);
    printf("\nEnter the number of column: ");
    scanf("%d", &col);
    printf("\nEnter the number of non-zero elements:\n");
    scanf("%d", &e);
    if (e > (row * col) / 3)
    {
        printf("\nThe matrix is not a sparse matrix\n");
        exit(1);
    }
    for (i = 0; i < e; i++)
    {
        printf("\nEnter the position of row for %d place: ", i + 1);
        scanf("%d", &r[i]);
        printf("\nEnter the position of column for %d place: ", i + 1);
        scanf("%d", &c[i]);
        printf("Enter the value at given row and column for %d place: ", i + 1);
        scanf("%d", &v[i]);
    }
    printf("\nThe Sparse Matrix is:\n");
    for (i = 0; i <= row; i++)
    {
        for (j = 0; j <= col; j++)
        {
            if (i == r[p] && j == c[p])
            {
                printf("%d\t", v[q]);
                p++;
                q++;
            }
            else
                printf("0\t");
        }
        printf("\n");
    }
    return 0;
}