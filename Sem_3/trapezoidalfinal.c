#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	float a,b,h,x,y,y0,yn,xn,s,r;
	int i,n;
	float f(float);
	printf("\n enter the lower limit:");
	scanf("%f",&a);
	printf("\n enter the upper limit:");
	scanf("%f", &b);
	printf("\n enter the interval:");
	scanf("%d",&n);
	h=(b-a)/n;
	y0=f(a);
	yn=f(b);
	x=a+h;
	s=0;
	for(i=1;i<=(n-1);i++)
	{
		y=f(x);
		s=s+y;
		x=x+h;
	}
	r=(h/2)*((y0+yn)+(2*s));
	printf("\n the result is: %f ",r);
	getch();
}
float f(float x)
{
	return(1/(1+x));
}
	
