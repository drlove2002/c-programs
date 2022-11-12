//liner Queue using doubly linked list

#include <stdio.h>
#include <stdlib.h>

//Defining queue variables
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

//check if Queue is empty
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
void print_q(node *head)
{
    node *ptr = head;
    if (is_empty(head))
    {
        printf("[!] Queue is empty!\n");
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

//insert link at the end of a queue
node *enqueue(node *head)
{
    node *link = create_node(); //create a node
    node *current = head;

    if (is_empty(head)) //If the Linked List is empty, then make the new node as head
        head = link;
    else
    {
        while (current->next != NULL) //Else traverse till the last node
            current = current->next;  //move to next node
        current->next = link;         //point it to new end node
        link->prev = current;         //point new end node's prev to old end node
    }
    return head;
}

//delete first node from the queue
node *dequeue(node *head)
{
    node *tempNode = head; //save reference to first node
    if (is_empty(head))
        printf("[!] Queue is underflow\n");
    else
    {
        head = head->next; //mark next to first node as first
        printf("[!] %d deleted.\n", tempNode->data);
        free(tempNode);
    }
    return head;
}

int main()
{
    int opt;
    node *q = NULL;

    while (1)
    {
        printf("-----------[MENU]-----------\n");
        printf("1) Insert\n");
        printf("2) Delete\n");
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
            q = enqueue(q);
            break;
        case 2:
            q = dequeue(q);
            break;
        case 3:
            print_q(q);
            break;
        default:
            printf("[x] Error! Wrong Input\n> please type a number between 0 to 3\n");
        }
    }
    return 0;
}