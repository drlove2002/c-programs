//Circular Queue using linked list

#include <stdio.h>
#include <stdlib.h>

//Defining queue variables
typedef struct node
{
    int data;
    struct node *next;
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
    ptr->next = ptr;
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
    while (ptr->next != head) //start from the beginning
    {
        printf("%d-->", ptr->data);
        ptr = ptr->next;
    }
    printf("%d-->", ptr->data);
    printf("\n");
}

//insert link at the end of a queue
node *enqueue(node *head)
{
    node *link = create_node(); //create a node
    node *current = head;

    if (head == NULL) //If the Linked List is empty, then make the new node as head
    {
        head = link;
        link->next = link;
    }
    else
    {
        while (current->next != head) //Else traverse till the last node
            current = current->next;  //move to next link

        link->next = head;    //point it to old first node
        head = link;          //point first to new first node
        current->next = link; //point it to new head
    }

    printf("[!] %d successfully added.\n", head->data);
    return head;
}

//delete first node from the queue
node *dequeue(node *head)
{
    node *current = head;
    node *previous = head;

    if (head == NULL)
    {
        printf("[!] Queue is empty!\n");
    }
    else
    {
        while (current->next != head) //Else traverse till the last node
        {
            previous = current;
            current = current->next; //move to next link
        }
        if (previous->next != head)
            previous->next = head; //point it to new end node
        else
            head = NULL;
        printf("[!] %d successfully deleted.\n", current->data);
        free(current);
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