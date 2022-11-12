/*Search node by value in a linked list*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

/*display a Linked list*/
void print_list(node *head)
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

/*Create a new node*/
node *create_node()
{
    node *ptr = (node *)malloc(sizeof(node));
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    return ptr;
}

/*insert node at the end of a linked list*/
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

/*Search node by value in a linked list*/
void search(node *head, int val)
{
    if (head == NULL) //If the Linked List is empty, then return
    {
        printf("[!] List is empty\n");
        return;
    }
    node *cur;
    int pos = 1;
    for (cur = head; cur != NULL; cur = cur->next)
    {
        if (cur->data == val)
        {
            printf("[!] Data Found!\n");
            printf("---[%dth node]---\n> Value: %d\n> Next-Node: %x\n", pos, cur->data, cur->next);
            return;
        }
        pos++;
    }
    printf("[!]Your entered value is not found in Linked list!\n");
}

int main()
{
    int n, i, temp;
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
        printf("Enter a value to search in Linked list:\n> ");
        scanf("%d", &temp);
        search(head, temp);
        printf("[!] Press CTRL + C to exit\n");
    }
    return 0;
}