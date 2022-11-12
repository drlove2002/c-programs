#include <stdio.h>
#include <math.h>
void symmetric(int *arr, int d)
{
    int i, j, k, m;
    m = floor(sqrt(2 * d));
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i >= j)
            {
                k = ((i * (i + 1)) / 2) + j;
                printf("%d\t", arr[k]);
            }
            else
            {
                k = ((j * (j + 1)) / 2) + i;
                printf("%d\t", arr[k]);
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
    symmetric(arr, d);
    return 0;
}