#include<stdio.h>
int main()
{
	int i,j,range, temp, sum, currentDigit, fact;
    printf("Provide a range: ");
    scanf("%d",&range);
    
    for (i = 1; i < range; i++){
    	temp = i;
    	sum = 0;
  		while(temp!=0){
    		currentDigit = temp % 10;
    		fact = 1;

    		// finding factorial of the currentDigit
    		for(j=1; j<=currentDigit; j++){
      			fact *= j;
    		}

    	sum += fact;
    	temp /= 10;
  		}
  	if(sum == i){
    	printf("%d is Krishnamurthy Number.\n",i);
  	}
  }
  return 0;
}
