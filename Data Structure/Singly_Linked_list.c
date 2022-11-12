#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

/*display the list*/
void print_list(struct node *head)
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

/*insert node at the first location*/
node *insert_at_first(node *head)
{
    node *link = create_node(); //create a node
    if (head != NULL)
    {
        link->next = head; //point it to old first node
    }
    head = link; //point first to new first node
    return head;
}

/*insert node at a certain location*/
node *insert_at_pos(node *head, int pos)
{

    int i;
    node *link = create_node(); //create a node

    //start from the first node
    node *current = head;
    node *previous = NULL;

    if (head == NULL)
    {
        printf("[!] Linked list is empty!\n");
        return head; //if list is empty
    }

    for (i = 0; i < pos; i++)
    { //itarate through list
        if (current->next == NULL)
        {
            printf("[x] Error! Position Must be between 1 to %d\n", length(head));
            return head; //if it is last node
        }
        else
        {
            previous = current;      //store reference to current node
            current = current->next; //move to next node
        }
    }

    if (current == head) //found a match, update the node
    {
        link->next = head;
        head = link;
    }
    else
    {
        link->next = current;
        previous->next = link; //bypass the current node
    }
    printf("[!] Data successfully saved.\n");
    return head;
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

/*delete first node from a Linked list*/
node *delete_from_first(node *head)
{
    node *tempNode = head; //save reference to first link
    if (head == NULL)
        printf("[!] Linked list is empty!\n");
    else
    {
        head = head->next; //mark next to first node as first
        printf("[!] %d successfully deleted.\n", tempNode->data);
        free(tempNode);
    }
    return head; //return the new head
}

/*delete end node from a Linked list*/
node *delete_from_end(node *head)
{
    node *current = head;
    node *previous = NULL;

    if (head == NULL)
        printf("[!] Linked list is empty!\n");
    else
    {
        while (current->next != NULL) //Else traverse till the last node
        {
            previous = current;
            current = current->next; //move to next node
        }
        previous->next = NULL; //point it to new end node
        printf("[!] %d successfully deleted.\n", current->data);
        free(current);
    }
    return head;
}

/*delete a node with given position from a Linked list*/
node *delete_from_pos(node *head, int pos)
{

    int i;
    //start from the first link
    node *current = head;
    node *previous = NULL;

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
    if (current == head)      //found a match, update the node
        head = current->next; //change first to point to next link
    else
        previous->next = current->next; //bypass the current link
    printf("[!] %d successfully deleted.\n", current->data);
    free(current);
    return head;
}

int main()
{
    int n, opt, i;
    struct node *head = NULL;
    while (1)
    {
        printf("-----------[MENU]-----------\n");
        printf("0) EXIT\n");
        if (head == NULL)
            printf("1) Create a list\n");
        if (head != NULL)
        {
            printf("2) Display List\n");
            printf("3) Insert at the beginning\n");
            printf("4) Insert at the End\n");
            printf("5) Insert at the a certain Position\n");
            printf("6) Delete first node\n");
            printf("7) Delete last node\n");
            printf("8) Delete a certain node by Position\n");
        }
        printf("----------------------------\n");

        printf("> Choose an option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            system("cls");
            exit(0);
        case 1:
            printf("Enter list size: ");
            scanf("%d", &n);
            printf("Enter %d numbers [separated by single space]:\n> ", n);
            for (i = 0; i < n; i++)
                head = insert_at_end(head);
            printf("[!] List created.\n");
            break;
        case 2:
            break;
        case 3:
            printf("> Enter a integer: ");
            head = insert_at_first(head);
            printf("[!] Data successfully saved.\n");
            break;
        case 4:
            printf("> Enter a integer: ");
            head = insert_at_end(head);
            printf("[!] Data successfully saved.\n");
            break;
        case 5:
            printf("> Enter the position [Must be between 0 to %d]: ", length(head) - 1);
            scanf("%d", &n);
            head = insert_at_pos(head, n);
            break;
        case 6:
            head = delete_from_first(head);
            break;
        case 7:
            head = delete_from_end(head);
            break;
        case 8:
            printf("> Enter the position [Must be between 0 to %d]: ", length(head) - 1);
            scanf("%d", &n);
            head = delete_from_pos(head, n);
            break;
        default:
            printf("[x] Error! Wrong Input\n> please type a number between 0 to 8\n");
        }
        print_list(head);
        printf("\n");
    }
    return 0;
}
