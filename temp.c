#include <stdio.h>
#include <math.h>

void main()
{
    float x[] = {0, 1, 3, 4};    // All values of x
    float y[] = {5, 6, 50, 105}; // All values of f(x)
    float p = 2;                 // We have to find value of f(2)
    float temp, f[10], sum;
    int i, j, k = 0, n = 4;
    for (i = 0; i < n; i++)
    {
        temp = 1;
        k = i;
        for (j = 0; j < n; j++)
        {
            if (k == j)
            {
                continue;
            }
            else
            {
                temp = temp * ((p - x[j]) / (x[k] - x[j]));
            }
        }
        f[i] = y[i] * temp;
    }
    for (i = 0; i < n; i++)
    {
        sum = sum + f[i];
    }
    printf("\n f(%.1f) = %f", p, sum);
}
 
  