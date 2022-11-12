#include <stdio.h>

int fib(int n)
{
    int nextTerm;
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return (fib(n - 1) + fib(n - 2));
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("%dth Fibonacci Number: %d", n, fib(n));
    return 0;
}
