#include<stdio.h>
#include<conio.h>
#include<math.h>
#define F(X,Y) (X-Y)

void main()
{
 float x0, y0, n, h, y1, k1, k2, k3, k4,f;
 
 printf("Enter Initial Condition\n");
 printf("x0 = ");
 scanf("%f", &x0);
 printf("y0 = ");
 scanf("%f", &y0);
 printf("Enter calculation point n = ");
 scanf("%f", &n);
 printf("Enter the value of h : ");
 scanf("%f", &h);

 /* Runge Kutta Method */
 printf("\nx0\ty0\tyn\n");
 for(;x0<n;x0=x0+h)
 {
 	f=F(x0,y0);
  	k1 = h * f;
  	f=F(x0+h/2, y0+k1/2);
  	k2 = h * f;
  	f=F(x0+h/2, y0+k2/2);
  	k3 = h * f;
  	f=F(x0+h/2, y0+k3);
  	k4 = h * f;
  	y1 =y0 + ((k1+2*k2+2*k3+k4)/6);
  	
 	printf("\n k1=%4f",k1);
 	printf("\n k2=%4f",k2);
 	printf("\n k3=%4f",k3);
 	printf("\n k4=%4f",k4);
 	printf("\n y(%4f)=%4f",x0+h,y1);
 	
 	printf("\n Answer is = %.5f\n--------\n", y1);
  	y0 = y1;
 }
 getch();
}