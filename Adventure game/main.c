# include <stdio.h>

void main()
{
	char op;
    printf("WELCOME TO MY ADVENTURE GAME\n");
    printf("----------------------------\n");
    printf("You are in the middle of a forest\n Which way you want to go?\n");
    printf("> PRESS e for East\n> PRESS w for West\n> PRESS s for South\n> PRESS n for North\n");
    scanf("%c",&op);

    switch(op)
    {
        case 'e': 
            printf("You are going to the East side.");
            break;
        case 'w': 
            printf("You are going to the West side.");
            break;
        case 's': 
            printf("You are going to the South side.");
            break;
        case 'n': 
            printf("You are going to the North side.");
            break;
        default: 
            printf("Invalid entry~! try again..!");
    }
}


