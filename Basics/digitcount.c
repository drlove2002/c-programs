//WAP in c to count the number of digits of a given number
#include<stdio.h>
int main()
{
	int p,n,count=0;
	printf("Enter the number\n=>");
	scanf("%d",&n);
	p=n;
	while (p>0)
		{
			count++;
			p=p/10;
		}
	printf("Nunber of digits in %d is %d",n,count);	
	return 0;		
}
