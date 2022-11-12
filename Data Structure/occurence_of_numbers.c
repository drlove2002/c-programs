/*WAP to print the occurence of 
the number of the linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

/*display the list*/
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
        printf("[%d]-->", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

/*Create a new node*/
node *create_node(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Memory Unsatisfied!");
        exit(0);
    }
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

/*insert node at the end of a linked list*/
node *insert_at_end(node *head, int data)
{
    node *link = create_node(data); //create a link
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

/*swap two number's to their address*/
void swap(int *n1, int *n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

/*sort a linked list using bubbleSort*/
void bubbleSort(node *head)
{
    node *i, *j;
    for (i = head; i != NULL; i = i->next)
    {
        for (j = head; j->next != NULL; j = j->next)
        {
            if (j->data > j->next->data)
                swap(&j->data, &j->next->data);
        }
    }
}

/*Copy list1's all eliments to list2*/
void copy_list(node **list1, node **list2)
{
    node *ptr;
    for (ptr = *list1; ptr != NULL; ptr = ptr->next)
        *list2 = insert_at_end(*list2, ptr->data);
}

/*Free a linked list from heap memory*/
void free_list(node *head)
{
    node *ptr;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
        free(ptr);
}

/*prints the occurence of 
the numbers of the linked list*/
void print_occurrences(node *head)
{
    int occurence = 0;
    node *i, *temp_list;
    if (head == NULL) //if list is empty
        printf("[!] Linked list is empty!\n");
    else
    {
        temp_list = NULL;
        copy_list(&head, &temp_list);
        bubbleSort(temp_list);
        printf("--------------------------\n");
        for (i = temp_list; i != NULL; i = i->next)
        {
            if (i->next != NULL && i->data == i->next->data)
                occurence++;
            else
            {
                printf("> [%d] occured [%d] times.\n", i->data, occurence + 1);
                occurence = 0;
            }
        }
        printf("> Other numbers occured [0] times.\n");
        printf("--------------------------\n");
        free_list(temp_list);
    }
}

int main()
{
    int n, i, number;
    node *head = NULL;
    system("cls");
    printf("Enter list size: ");
    scanf("%d", &n);
    printf("Enter %d numbers [separated by single space]:\n> ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &number);
        head = insert_at_end(head, number);
    }
    printf("[!] List created.\n");
    print_list(head);
    print_occurrences(head);
    return 0;
}
