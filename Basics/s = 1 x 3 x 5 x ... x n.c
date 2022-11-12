// s = 1 * 2 * 3 *...* n
#include<stdio.h>
int main(void){
	int i=1,n,multi=1;
	printf("set the limit\n:>");
	scanf("%d",&n);
	while (i<=n)
		{
			multi = multi * i;
			i++;		
		}
	printf("Result: %d",multi);	
	return 0;	
}
