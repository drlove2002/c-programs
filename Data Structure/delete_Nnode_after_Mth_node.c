/*WAP to delete n node after Mth node of a linked list*/

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
        printf("%d-->", ptr->data);
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

/*Create a new node*/
node *create_node()
{
    node *ptr = (node *)malloc(sizeof(node));
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    return ptr;
}

/*insert link at the end of a linked list*/
node *insert_at_end(node *head)
{
    node *link = create_node(); //create a link
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

/*delete many nodes with given position from a Linked list*/
node *delete_many_from_pos(node *head, int quantity, int pos)
{

    int i;
    //start from the first link
    node *current = head;
    node *previous = NULL;
    node **temp = NULL;

    if (head == NULL)
    {
        printf("[!] Linked list is empty!\n");
        return head; //if list is empty
    }
    for (i = 1; i < pos; i++)
    { //itarate through list
        if (current->next == NULL)
        {
            printf("[x] Error! Position Must be between 1 to %d\n", length(head));
            return head; //if it is last node
        }
        else
        {
            previous = current;      //store reference to current link
            current = current->next; //move to next link
        }
    }
    if (current == head) //found a match, update the node
        temp = &head;
    else
        temp = &previous->next;
    for (i = 0; i < quantity; i++)
    {
        *temp = current->next; //bypass the current link
        free(current);
        current = *temp;
        if (current == NULL)
            break;
    }
    printf("[!]successfully deleted %d nodes from %dth node\n", quantity, pos);
    return head;
}

int main()
{
    int quantity, n, i;
    node *head = NULL;
    system("cls");
    printf("Enter list size: ");
    scanf("%d", &n);
    printf("Enter %d numbers [separated by single space]:\n> ", n);
    for (i = 0; i < n; i++)
        head = insert_at_end(head);
    printf("[!] List created.\n");
    print_list(head);
    while (1)
    {
        printf("How many node you want to delete: ");
        scanf("%d", &quantity);
        printf("Enter the position from where the deletation will start:\n> ");
        scanf("%d", &n);
        head = delete_many_from_pos(head, quantity, n);
        print_list(head);
    }
    return 0;
}
