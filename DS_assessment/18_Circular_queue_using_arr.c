//Circular Queue using array

#include <stdio.h>
#include <stdlib.h>

//Defining queue variables
int size, front, rear;

//check if Queue is full
int is_full()
{
    if ((rear + 1) % size == front)
        return 1;
    return 0;
}

//check if Queue is empty
int is_empty()
{
    if (front == -1)
        return 1;
    return 0;
}

//print Queue's eliments
void print_queue(int *q)
{
    int i;
    if (is_empty())
        printf("Queue is empty!\n");
    else
    {
        printf("Eliments are:\n> ");
        for (i = front; i != rear; i = (i + 1) % size)
            printf("%d ", q[i]);
        printf("%d\n", q[i]);
    }
}

//insert a new item at the end into queue
void qinsert(int *q, int data)
{
    if (is_full())
        printf("Queue is full you can't insert any more eliments!\n");
    else
    {
        rear = (rear + 1) % size;
        q[rear] = data;
        if (is_empty())
            front++;
        printf("%d added to the queue!\n", q[rear]);
    }
}

//delete first item from queue
int qdelete(int *q)
{
    if (is_empty())
    {
        printf("Queue is empty you can't delete any more eliments!\n");
        return -999999;
    }
    else
    {
        int temp = q[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
        return temp;
    }
}

int main()
{
    int opt, num;
    int q[20];
    front = rear = -1;
    printf("Enter stack size: ");
    scanf("%d", &size);
    if (size > 20)
    {
        printf("[ERROR] Max queue size must be less than 20\n");
        exit(1);
    }
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