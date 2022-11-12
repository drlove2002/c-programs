// s = 2 + 4 + 6... n
#include<stdio.h>
int main(void){
	int i=2,n,sum=0;
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
