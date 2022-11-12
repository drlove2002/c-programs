#include <stdio.h>
#include <math.h>

void main()
{
	float x[10], y[10], temp = 1, f[10], sum, p;
	int i, n, j, k = 0, c;
	printf("\n how many records will you be enter:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("\n enter the value of x%d : ", i);
		scanf("%f", &x[i]);
		printf("\n enter the value of f(x%d): ", i);
		scanf("%f", &y[i]);
	}
	printf("\n enter x for finding f(x):");
	scanf("%f", &p);
	for (i = 0, temp = 1, k = i; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (k != j)
				temp = temp * ((p - x[j]) / (x[k] - x[j]));
		f[i] = y[i] * temp;
	}
	for (i = 0; i < n; i++)
		sum = sum + f[i];
	printf("\n f(%.1f) = %f", p, sum);
}