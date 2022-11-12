// s = 1 + 3 + 5... n
#include<stdio.h>
int main(void){
	int i=1,n,sum=0;
	printf("set the limit\n:>");
	scanf("%d",&n);
	while (i<=n)
		{
			sum = sum + i;
			i= i + 2;		
		}
	printf("%d",sum);	
	return 0;	
}
