/*Hashing*/

#include <stdio.h>
#include <stdlib.h>

/*Defining struct node*/
typedef struct node
{
    int data;
    struct node *next;
} node;

/*Pointer array allocate dynamically*/
node **setup(node **arr, int n)
{
    int i;
    arr = (node **)malloc(n * sizeof(node *)); //
    for (i = 0; i < n; i++)
        arr[i] = NULL; // Initialize all the locations to null
    return arr;
}

/*Create a new node*/
node *create_node()
{
    node *ptr = (node *)malloc(sizeof(node));
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    return ptr;
}

/*Hash function for hashing*/
int hash_func(int key, int n)
{
    return key % n;
}

/*input an eliment in bucket*/
node **input(node **arr, int n)
{
    node *temp = create_node();
    int bucket_index = hash_func(temp->data, n);
    int list_index;
    node *ptr = arr[bucket_index];
    if (ptr == NULL)
    {
        arr[bucket_index] = temp;
        list_index = 0;
    }
    else
    {
        list_index = 1;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            list_index++;
        }
        ptr->next = temp;
    }
    printf("%d saved in, bucket index: %d , list index: %d\n", arr[bucket_index]->data, bucket_index, list_index);
    return arr;
}

/*print the hashing structure*/
void print_arr(node **arr, int n)
{
    int i;
    node *ptr;
    printf("Eliments are:\n");
    for (i = 0; i < n; i++)
    {
        ptr = arr[i];
        printf("[%d] ", i);
        if (ptr == NULL)
            printf("NULL");
        else
            while (ptr != NULL)
            {
                printf("%d-> ", ptr->data);
                ptr = ptr->next;
            }
        printf("\n");
    }
}

/*Search an eliment in the list*/
void search_item(node **arr, int n, int key)
{
    int bk_index = hash_func(key, n), pos = 0, flag = 0;
    node *ptr = arr[bk_index];
    while (ptr != NULL)
    {
        if (key == ptr->data)
        {
            printf("%d found in, bucket index: %d, linked list index: %d\n", ptr->data, bk_index, pos);
            flag = 1;
        }
        ptr = ptr->next;
        pos++;
    }
    if (flag == 0)
        printf("Data not found in bucket!\n");
}

int main()
{
    int n, opt, key;
    node **arr;
    printf("Enter the bucket size: ");
    scanf("%d", &n);     //User intup the bucket size
    arr = setup(arr, n); //setup the bucket
    while (1)
    {
        printf("-----------[MENU]-----------\n");
        printf("0) EXIT\n");
        printf("1) Enter new eliment\n");
        printf("2) Search eliment in list\n");
        printf("3) Print the hash structure\n");
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
            arr = input(arr, n);
            break;
        case 2:
            printf("Enter an integer: ");
            scanf("%d", &key);
            search_item(arr, n, key);
            break;
        case 3:
            print_arr(arr, n);
            break;
        default:
            printf("[x] Error! Wrong Input\n> please type a number between 0 to 3\n");
        }
    }
    return 0;
}