#include<stdio.h>
int main(void){
	int i,n;
	printf("set the limit\n:>");
	scanf("%d",&n);
	i=1;
	while (i<=n)
		{
			printf("%d\n",i);
			i = i + 1;		
		}
	return 0;	
}
