// s = 1 + 1/2 + 1/3... 1/n
#include<stdio.h>
int main(void){
	int i=1,n;
	float sum=0;
	printf("set the limit\n:>");
	scanf("%d",&n);
	while (i<=n)
		{
			sum = sum + (float)1/i;
			i++;		
		}
	printf("Result: %f",sum);	
	return 0;	
}
