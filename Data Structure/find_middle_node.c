// Find middle node
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

/*get the middle node of a linked list*/
node *get_middle_node(node *head)
{
    if (head == NULL) //If the Linked List is empty, then return
    {
        printf("[!] List is empty\n");
        return NULL;
    }
    node *cur = head;
    node *mid = head;
    int i = 0;
    /* traverse till the last node and traverse mid
     to next node in every 2 traverse or cur*/
    while (cur->next != NULL)
    {
        cur = cur->next;
        i++;
        if (i == 2)
        {
            i = 0;
            mid = mid->next;
        }
    }
    return mid;
}

int main()
{
    int n, i;
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
    temp = get_middle_node(head);
    printf("---[Middle node]---\n> Value: %d\n> Next-Node: %x\n", temp->data, temp->next);
    return 0;
}