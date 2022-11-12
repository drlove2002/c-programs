/*WAP to take a linked list from user
 and print the reverse*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
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

void print_reverse_list(node *head) //display the list in reverse order
{
    node *ptr = head;
    if (head == NULL)
    {
        printf("[!] Linked list is empty!\n");
        return; //if list is empty
    }
    printf("> ");
    while (ptr->next != NULL) //start from beginning and itarate to laft node
    {
        ptr = ptr->next;
    }
    while (ptr != NULL) //reverse print
    {
        printf("[%d]<--", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
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
    ptr->prev = NULL;
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

        link->prev = current; //point it to old end node
        current->next = link; //point it to new end node
    }
    return head;
}

int main()
{
    int number, n, i;
    node *head = NULL;
    system("cls");
    printf("Enter list size: ");
    scanf("%d", &n);
    printf("Enter %d numbers [separated by single space]:\n> ", n);
    for (i = 0; i < n; i++)
        head = insert_at_end(head);
    printf("[!] List created.\n");
    print_list(head);

    printf("---Print in reverse order---\n");
    print_reverse_list(head);
    return 0;
}
