#include <stdio.h>
int main(void){
int num;
printf("Enter your marks:");
scanf("%d",&num);
	if (num>100)
	{
		printf(" ! Wrong data ");
	} 
	else if(num >= 80)
	{
		printf(" You got A grade"); 
	}
	else if ( num >=60)
	{ 
		printf(" You got B grade");
	}
	else if ( num >=40)
	{
		printf(" You got C grade");
	}
	else if ( num < 40)
	{
		printf(" You Failed in this exam");
	}
}
