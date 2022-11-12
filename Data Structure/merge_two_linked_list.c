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
node *merge_two_list(node *list1, node *list2)
{
    /*If any of the Linked List is empty, then return*/
    if ((list1 == NULL) || (list2 == NULL))
    {
        printf("[!] One of the List is empty\n");
        return NULL;
    }
    node *cur = list1;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = list2;
    return list1;
}

/*Search node by value in a linked list*/
node *create_list(node *head)
{
    int n, i;
    printf("Enter list size: ");
    scanf("%d", &n);
    printf("Enter %d numbers [separated by single space]:\n> ", n);
    for (i = 0; i < n; i++)
        head = insert_at_end(head);
    printf("[!] List created.\n");
    print_list(head);
    return head;
}

int main()
{
    node *list1, *list2, *result;
    list1 = list2 = result = NULL;
    system("cls");
    list1 = create_list(list1);
    list2 = create_list(list2);
    result = merge_two_list(list1, list2);
    printf("---[Merge list]---\n");
    print_list(result);
    return 0;
}