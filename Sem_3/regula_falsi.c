#include<stdio.h>
#include<math.h>
#define ESP 0.0001
#define F(x) (x) * (x) * (x) +  2 * (x) - 2

void main()
{
	float a,b,fa,fb,h,xn,fxn;
	do
	{
		printf("\nenter the value of a:");
	scanf("%f",&a);
	}while(F(a) > 0 );
	do
	{
		printf("\nenter the value of b:");
	scanf("%f",&b);
	}while(F(b) < 0 );
	printf("\n______________________________________________\n");
	printf("\n  a\t  b\t  fa\t  fb\t  h\t  xn\t  fxn\t ");
	printf("\n______________________________________________\n");
	do
	{
		fa=F(a);
		fb=F(b);
		h=((fa*(b-a)) / (fa + fb));
		xn=a+h;
		fxn=F(xn);	
		printf("\n  %f\t  %f\t  %f\t  %f\t  %f\t  %f\t  %f\t ",a,b,fa,fb,h,xn,fxn);
		if(a*fxn<0)
		{
			a=xn;
		}
		else
		{
			b=xn;
		}
	}while(fabs(fxn)>ESP);
	printf("\n_________________________________________________________\n");
	printf("\n\n app.root = %f ", xn);
}

