#include<stdio.h>

void palindrom(int n){
	int r,m,s=0;
	m=n;			
	while(m>0){
		r=m%10;			
		s=(s*10)+r;
		m=m/10;
	}
	if(n==s)		
		printf("%d is a palindrome number\n",n); 				       
	else			
		printf("%d is not a palindrome number\n",n);
}
		
int main(void){					
	int r,m,n,s=0;			
	printf("Enter the number: ");	
	scanf("%d",&n);
	palindrom(n);			
}
