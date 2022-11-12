#include<stdio.h>
#include<conio.h>
#include<math.h>
#define ESP 0.001
#define F(x) (x) * (x) * (x) - (x) * (x) + (x) + 7
void main()
{
	int n = 1;
	float a,b,x;
	double f1,fx,f0,t;
	printf("enter the value of x0:");
	scanf("%f",&a);
	printf("enter the value of x1:");
	scanf("%f",&b);
	printf("\n");
	printf("\niteration\t a\t b\t x\t  fx");
	printf("\n");
	do
	{
		x=(a+b)/2;
		f0=F(a);
		f1=F(b);
		fx=F(x);
		printf("\n%d\t %f %f %f %1f ",n,a,b,x,fx);
		if(f0*fx<0)
			b=x;
		else
			a=x;
		n++;
	}while(fabs(fx) > ESP);
	printf("\n");
	printf("\n approximate root= %f",x);
	getch();
}
