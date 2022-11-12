/*Find the nth node from the end of the linked list*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void print_list(node *head) //display the list
{
    node *ptr = head;
    if (head == NULL)
    {
        printf("[!] Linked list is empty!\n");
        return; //if list is empty
    }
    printf("> ");
    while (ptr != NULL) //start from the beginning
    {
        printf("[%d]-->", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int length(node *head)
{
    int length = 0;
    node *current;

    for (current = head; current != NULL; current = current->next)
    {
        length++;
    }
    return length;
}

/*create a new node*/
node *create_node()
{
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Memory Unsatisfied!");
        exit(0);
    }
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    return ptr;
}

/*insert node at the end of a linked list*/
node *insert_at_end(node *head)
{
    node *link = create_node(); //create a node
    node *current = head;

    if (current == NULL) //If the Linked List is empty, then make the new node as head
        head = link;
    else
    {
        while (current->next != NULL) //Else traverse till the last node
            current = current->next;  //move to next link
        current->next = link;         //point it to new end node
    }
    return head;
}

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(node *head, int n)
{
    int i;
    int length = 1;
    //start from the first link
    node *ptr;

    if (head == NULL)
        return -1; //if list is empty

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        length++;
    }
    ptr = head;
    if ((length - n) <= 0)
        return -1;
    for (i = 1; i < (length - n); i++)
        ptr = ptr->next; //move to previous node
    return ptr->data;
}

int main()
{
    int number, n, i;
    node *head = NULL;
    node *temp = NULL;
    system("cls");
    printf("Enter list size: ");
    scanf("%d", &n);
    printf("Enter %d numbers [separated by single space]:\n> ", n);
    for (i = 0; i < n; i++)
        head = insert_at_end(head);
    printf("[!] List created.\n");
    print_list(head);

    printf("[!] Enter value of n to get nth node from the end of the linked list \n [n Must be between 1 to %d]\n> ", length(head));
    scanf("%d", &n);
    printf("%dth node's value: %d", n, getNthFromLast(head, n));
    return 0;
}
