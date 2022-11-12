/*WAP to remove the dublicate eliment
 from storted linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void swap(int *n1, int *n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

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

node *del_node(node *head, node **prev, node **cur)
{
    node *temp = *cur;
    if (*cur == head)
        head = head->next;
    else
        (*prev)->next = (*cur)->next;
    *cur = (*cur)->next;
    free(temp);
    return head;
}

node *bubbleSort(node *head)
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
    return head;
}

/*get the middle node of a linked list*/
node *remove_dublicate_node(node *head)
{
    if (head != NULL)
    {
        head = bubbleSort(head);
        node *cur = head;
        node *prev = NULL;
        while (cur->next != NULL)
        {
            if (cur->data == cur->next->data)
                head = del_node(head, &prev, &cur);
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
    }
    return head;
}

int main()
{
    int n, i;
    node *head = NULL;
    system("cls");
    printf("Enter list size: ");
    scanf("%d", &n);
    printf("Enter %d numbers [separated by single space]:\n> ", n);
    for (i = 0; i < n; i++)
        head = insert_at_end(head);
    printf("[!] List created.\n");
    print_list(head);

    printf("---[Filterd list]---\n");
    head = remove_dublicate_node(head);
    print_list(head);

    return 0;
}