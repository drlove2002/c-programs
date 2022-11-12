/*Stacks using dynamic arrey*/

#include <stdio.h>
#include <stdlib.h>

/*Defining struct node*/
typedef struct stack
{
    int size, top;
    int *arr;
} stack;

/*Create and alocate a stack*/
stack *create_stack(int size)
{
    stack *new_stack = (stack *)malloc(sizeof(stack));
    new_stack->size = size;
    new_stack->top = -1;
    new_stack->arr = (int *)malloc(new_stack->size * sizeof(int));
    return new_stack;
}

/*check if stack is full*/
int is_full(stack *stack)
{
    if (stack->top == stack->size - 1)
        return 1;
    return 0;
}

/*check if stack is empty*/
int is_empty(stack *stack)
{
    if (stack->top == -1)
        return 1;
    return 0;
}

/*print array's eliments*/
void print_stack(stack *stack)
{
    int i, j;
    if (is_empty(stack))
        printf("stack is empty!\n");
    else
    {
        printf("Eliments are:\n> ");
        for (i = stack->top; i >= 0; i--)
        {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

//push new int into stack
void push(stack *stack, int data)
{
    if (is_full(stack))
        printf("stack is full! you can't push\n");
    else
    {
        stack->top++;
        stack->arr[stack->top] = data;
        printf("> %d Pushed into stack!\n", data);
    }
}

//pop the top int from stack
void *pop(stack *stack)
{
    if (stack->top == -1)
        printf("stack is already empty! you can't pop\n");
    else
    {
        stack->top--;
        printf("> %d Popped from stack!\n", stack->arr[stack->top + 1]);
    }
}

int main()
{
    int opt, num, size;
    printf("Enter stack size: ");
    scanf("%d", &size);
    stack *Stack = create_stack(size);
    while (1)
    {
        printf("-----------[MENU]-----------\n");
        printf("0) EXIT\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Print\n");
        printf("----------------------------\n");
        printf("> Choose an option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            system("cls");
            exit(0);
        case 1:
            printf("Enter an integer: ");
            scanf("%d", &num);
            push(Stack, num);
            break;
        case 2:
            pop(Stack);
            break;
        case 3:
            print_stack(Stack);
            break;
        default:
            printf("[x] Error! Wrong Input\n> please type a number between 0 to 3\n");
        }
    }
    return 0;
}