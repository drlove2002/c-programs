//Stack using doubly linked list

#include <stdio.h>
#include <stdlib.h>

//Defining Stack variables
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

//check if Stack is empty
int is_empty(node *head)
{
    if (head == NULL)
        return 1;
    return 0;
}

//Create a new node
node *create_node()
{
    node *ptr = (node *)malloc(sizeof(node));
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

//display a Linked list
void print_stack(node *head)
{
    node *ptr = head;
    if (is_empty(head))
    {
        printf("[!] Stack is empty!\n");
        return; //if list is empty
    }
    printf("> ");
    while (ptr != NULL) //start from the beginning
    {
        printf("%d-->", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

//Push a node in stack
node *push(node *head)
{
    node *new_node = create_node(); //create a node
    if (!is_empty(head))
    {
        new_node->next = head; //point it to old first node
        head->prev = new_node; //point old first node's prev to new first node
    }
    head = new_node; //point first to new first node
    printf("[!] %d pushed into stack.\n", new_node->data);
    return head;
}

//pop the first node from the Stack
node *pop(node *head)
{
    node *tempNode = head; //save reference to first node
    if (is_empty(head))
        printf("[!] Stack underflow\n");
    else
    {
        head = head->next; //mark next to first node as first
        printf("[!] %d Popped from stack.\n", tempNode->data);
        free(tempNode);
    }
    return head;
}

int main()
{
    int opt;
    node *stack = NULL;

    while (1)
    {
        printf("-----------[MENU]-----------\n");
        printf("1) PUSH\n");
        printf("2) POP\n");
        printf("3) Print\n");
        printf("0) EXIT\n");
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
            stack = push(stack);
            break;
        case 2:
            stack = pop(stack);
            break;
        case 3:
            print_stack(stack);
            break;
        default:
            printf("[x] Error! Wrong Input\n> please type a number between 0 to 3\n");
        }
    }
    return 0;
}