#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void push(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

struct Node *sortedMerge(struct Node *a, struct Node *b)
{
    if (a == NULL)
    {
        return b;
    }

    else if (b == NULL)
    {
        return a;
    }

    struct Node *result = NULL;

    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

void frontBackSplit(struct Node *source, struct Node **frontRef,
                    struct Node **backRef)
{

    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    struct Node *slow = source;
    struct Node *fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void mergesort(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    struct Node *a;
    struct Node *b;

    frontBackSplit(*head, &a, &b);

    mergesort(&a);
    mergesort(&b);

    *head = sortedMerge(a, b);
}

int main(void)
{

    int keys[10], size;
    printf("Enter the array size::");
    scanf("%d", &size);
    printf("Enter the array elements::");
    for (int i = 0; i <= size; i++)
    {
        scanf("%d", &keys[i]);
    }
    int n = sizeof(keys) / sizeof(keys[0]);

    struct Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        push(&head, keys[i]);
    }

    mergesort(&head);

    printList(head);

    return 0;
}