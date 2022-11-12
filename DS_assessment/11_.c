#include <stdio.h>

void upper_triangular(int *arr, int n)
{
    int i, j, k = 0;
    printf("\nThe upper triangular matrix is: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i <= j)
            {
                printf("%d\t", arr[k]);
                k++;
            }
            else
                printf("0\t");
        }
        printf("\n");
    }
}
void lower_triangular(int *arr, int n)
{
    int i, j, k = 0;
    printf("\nThe lower triangular matrix is: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i < j)
                printf("0\t");
            else
            {
                printf("%d\t", arr[k]);
                k++;
            }
        }
        printf("\n");
    }
}
int main()
{
    int arr[50], n, d, i;
    printf("\nEnter the dimension of the matrix: ");
    scanf("%d", &n);
    d = (n * (n + 1) / 2);
    printf("\nEnter the elements of the Matrix (row-wise):\n");
    for (i = 0; i < d; i++)
        scanf("%d", &arr[i]);
    upper_triangular(arr, n);
    lower_triangular(arr, n);
    return 0;
}