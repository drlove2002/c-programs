#include <stdio.h>

void fib(int n,int *t1,int *t2){
	int nextTerm;

	if(n>0) {
        printf("%d ", *t1);
        nextTerm = *t1 + *t2;
        *t1 = *t2;
        *t2 = nextTerm;
        fib(n-1,t1,t2);
    }	
}

int main() {
    int n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
	fib(n,&t1,&t2);
    return 0;
}

