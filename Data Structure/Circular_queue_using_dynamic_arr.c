//Queue using dynamic arrey

#include <stdio.h>
#include <stdlib.h>

//Defining struct node
typedef struct Queue
{
    int size, front, rear;
    int *arr;
} Queue;

//Create and alocate a Queue
Queue *create_queue(int size)
{
    Queue *new_queue = (Queue *)malloc(sizeof(Queue));
    new_queue->size = size;
    new_queue->front = new_queue->rear = -1;
    new_queue->arr = (int *)malloc(new_queue->size * sizeof(int));
    return new_queue;
}

//check if Queue is full
int is_full(Queue *queue)
{
    if ((queue->rear + 1) % queue->size == queue->front)
        return 1;
    return 0;
}

//check if Queue is empty
int is_empty(Queue *queue)
{
    if (queue->front == -1)
        return 1;
    return 0;
}

//print Queue's eliments
void print_queue(Queue *q)
{
    int i;
    if (is_empty(q))
        printf("Queue is empty!\n");
    else
    {
        printf("Eliments are:\n> ");
        for (i = q->front; i != q->rear; i = (i + 1) % q->size)
            printf("%d ", q->arr[i]);
        printf("%d\n", q->arr[i]);
    }
}

//insert a new item at the end into queue
void qinsert(Queue *q, int data)
{
    if (is_full(q))
        printf("Queue is full you can't insert any more eliments!\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = data;
        if (is_empty(q))
            q->front++;
        printf("%d added to the queue!\n", q->arr[q->rear]);
    }
}

//delete first item from queue
int qdelete(Queue *q)
{
    if (is_empty(q))
    {
        printf("Queue is empty you can't delete any more eliments!\n");
        return -999999;
    }
    else
    {
        int temp = q->arr[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front + 1) % q->size;
        return temp;
    }
}

int main()
{
    int opt, num, size;
    printf("Enter stack size: ");
    scanf("%d", &size);
    Queue *q = create_queue(size);
    while (1)
    {
        printf("-----------[MENU]-----------\n");
        printf("0) EXIT\n");
        printf("1) Insert\n");
        printf("2) Delete\n");
        printf("3) Print\n");
        printf("----------------------------\n");
        printf("> Choose an option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            system("cls");
            exit(0);
        case 1:
            printf("Enter an integer: ");
            scanf("%d", &num);
            qinsert(q, num);
            break;
        case 2:
            num = qdelete(q);
            if (num != -999999)
                printf("%d deleted from the queue!\n", num);
            break;
        case 3:
            print_queue(q);
            break;
        default:
            printf("[x] Error! Wrong Input\n> please type a number between 0 to 3\n");
        }
    }
    return 0;
}