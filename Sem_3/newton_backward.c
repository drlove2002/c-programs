// Write a program to implement Newton's backward interpolation.

#include <stdio.h>
#include <math.h>
float fact(int a)
{
	if(a == 0)
		return 1;
	else
		return (a * fact(a-1)); 
}
void main()
{
	float x[10], y[10][10], u, sum=0, temp, find;
	int n,i,j, k=0, m;
	printf("\nNo. of records you'll enter: ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		printf("\nEnter the value of x%d : ", i);
		scanf("%f", &x[i]);
		printf("\nEnter the value of f(x%d) : ", i);
		scanf("%f", &y[k][i]);
	}
	printf("\nEnter the x for finding f(x): ");
	scanf("%f", &find);
	for(i=1; i<n; i++)
	{
		for(j=0; j<n-1; j++)
		{
			y[i][j] = y[i-1][j+1] - y[i-1][j];
		}
	}
	printf("\n----------------------------------------------------\n");
	printf("\nx(i)\t y(i)\t y1(i)\t y2(i)\t y3(i)\t y4(i)\t y5(i)\n");
	printf("\n----------------------------------------------------\n");
	for(i=0; i<n; i++)
	{
		printf("\n %.2f", x[i]);
		for(j=0; j<n-i; j++)
		{
			if(y[j][i] != 0)
				printf("\t%.2f", y[j][i]);
		}
		printf("\n");
	}
	u = (find - n)/(x[k+1] - x[k]);
	printf("\nValue of u = %.2f", u);
	for(i=0; i<n-1; i++)
	{
		temp=1;
		for(j=0; j<i; j++)
		{
			temp = temp*(u+j);
		}
		m = fact(i);
		sum = sum + temp*(y[i][n-i-1]/m);
	}
	printf("\nValue of f(%.2f) = %.2f", find, sum);
	
}
