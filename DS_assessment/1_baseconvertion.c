#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Convert char to equivalent number*/
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

/*Convert number to equivalent char assci value*/
int assci(int temp)
{
    if (temp < 10)
        temp = temp + 48;
    else
        temp = temp + 55;
    return temp;
}

int others2decimal(char *arr, int base)
{
    int len = strlen(arr);
    int power = 1; // Initialize power of base
    int num = 0;   // Initialize result
    int i;

    // Decimal equivalent is str[len-1]*1 +
    // str[len-2]*base + str[len-3]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        // A digit in input number must be
        // less than number's base
        if (val(arr[i]) >= base)
        {
            printf("[x] You entred a Invalid Number!");
            exit(1);
        }

        num += val(arr[i]) * power;
        power = power * base;
    }

    return num;
}

int base_option()
{
    int base, opt;
    printf("-----[OPTIONS]-----\n");
    printf("1) Binary\n");
    printf("2) Octal\n");
    printf("3) Decimal\n");
    printf("4) Hexa-decimal\n");
    printf("-------------------\n> ");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        base = 2;
        break;
    case 2:
        base = 8;
        break;
    case 3:
        base = 10;
        break;
    case 4:
        base = 16;
        break;
    default:
        printf("Invalid try again!");
        base_option();
        break;
    }
    return base;
}

void decimal2others(char *arr, int base, int n)
{
    long int quotient;
    int i = 0, j, temp;
    quotient = n;
    while (quotient != 0)
    {
        temp = quotient % base;
        arr[i] = assci(temp);
        quotient = quotient / base;
        i++;
    }
    arr[i] = 0;
    strrev(arr);
}

int main()
{
    int n, base, result_base, result;
    char arr[30];
    printf("Enter the Base of the number:\n");
    base = base_option();
    printf("Enter the number:\n> ");
    if (base == 10)
        scanf("%d", &n);
    else
        scanf("%s", &arr);
    printf("Enter base of the result number:\n");
    result_base = base_option();

    if (base == 10)
    {
        decimal2others(arr, result_base, n);
        printf("The value of the decimal number in base %d is: %s", result_base, arr);
    }
    else if (result_base == 10)
    {
        result = others2decimal(arr, base);
        printf("The value of the %d base in decimal is: %d", base, result);
    }
    else
    {
        decimal2others(arr, result_base, n);
        result = others2decimal(arr, base);
        printf("The value of the base %d in base %d is: %d", base, result_base, result);
    }
}