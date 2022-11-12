/*WAP to delete the eliments in 
an linked list whos sum is equal to ZERO
*/

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

/*get the middle node of a linked list*/
node *remove_sum_zero_pair(node *head)
{
    if (head != NULL)
    {
        int flag = 0;
        node *i, *j, *prev_i, *prev_j;
        i = head;
        prev_i = prev_j = NULL;
        while (i != NULL)
        {
            for (j = head; j != NULL; j = j->next)
            {
                if ((i->data + j->data) == 0)
                {
                    flag = 1;
                    break;
                }
                prev_j = j;
            }
            if (flag == 1)
            {
                head = del_node(head, &prev_i, &i);
                if (i == j)
                    i = i->next;
                head = del_node(head, &prev_j, &j);
                flag = 0;
            }
            else
            {
                prev_i = i;
                i = i->next;
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
    head = remove_sum_zero_pair(head);
    print_list(head);

    return 0;
}