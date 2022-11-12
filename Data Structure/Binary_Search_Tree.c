#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *l, *r;
} node;

/*Create a new node*/
node *create_node(int key)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = key;
    ptr->l = ptr->r = NULL;
    return ptr;
}

/*inorder traversal of BST*/
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->l);
    printf("%d ", root->data);
    inorder(root->r);
}

/*preorder traversal of BST*/
void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    inorder(root->l);
    inorder(root->r);
}

/*postorder traversal of BST*/
void postorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->l);
    inorder(root->r);
    printf("%d ", root->data);
}

/*insert a new node with given key in BST*/
node *insert(node *root, int key)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
        return create_node(key);

    /* Otherwise, recur down the tree */
    if (key < root->data)
        root->l = insert(root->l, key);
    else if (key > root->data)
        root->r = insert(root->r, key);

    return root; //return the (unchanged) node pointer
}

int main()
{
    int n, opt, i;
    printf("Enter a number to create the root:");
    scanf("%d", &n);
    node *root = insert(NULL, n);
    while (1)
    {
        printf("-----------[TREE MENU]-----------\n");
        printf("1) Insert a new node\n");
        printf("2) InOrder\n");
        printf("3) PreOrder\n");
        printf("4) PostOrder\n");
        printf("Press 0 to EXIT\n");
        printf("----------------------------\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            system("cls");
            exit(0);
        case 1:
            printf("Enter a number:");
            scanf("%d", &n);
            insert(root, n);
            break;
        case 2:
            printf("InOrder Represetation:");
            inorder(root);
            break;
        case 3:
            printf("PreOrder Represetation:");
            preorder(root);
            break;
        case 4:
            printf("PostOrder Represetation:");
            postorder(root);
            break;
        default:
            printf("[x] Error! Wrong Input\n");
        }
        printf("\n");
    }
    return 0;
}