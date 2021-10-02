//Author : Sanjana Sawant

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *left;
    struct node *right;
}node;

void tr_menu(node *root);
int menu();

node* create();
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);

node* search(node *root, int item);
node *pos=NULL;
void search_algo(node *root);

void main()
{
    node *root;
    int ch;

    root=create();

    while(1)
    {
        printf("\n------Menu----");
        printf("\n1. Tree Traversal");
        printf("\n2. Search node");
        printf("\n3. Exit");
        printf("\nEnter your choice : ");

        scanf("%d", &ch);

        switch(ch)
        {
            case 1: tr_menu(root);
                    break;
            case 2: search_algo(root);
                    break;
            case 3: exit(0);
                    break;
            default: printf("\nInvalid choice!!");
        }
    }

    printf("\n\n");
    return;

}


node* search(node *root, int item)
{
    if(root==NULL)
    {
        //printf("\nItem not found in the tree ");
        pos=NULL;
        return root;
    }
    if (root->info==item)
    {
        pos=root;
        return root;
    }
    else if(item < root->info)
    {
        search(root->left, item);
    }
    else
    {
       search(root->right, item);
    }
}

void search_algo(node *root)
{
    int item;
    printf("\nEnter the node to search: ");
    scanf("%d", &item);
    pos=search(root, item);
    if(pos==NULL)
        printf("\nItem NOT found in the BST \n\n");
    else
        printf("\nItem found in the BST \n\n");
}

void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);

        printf("\n%d ",root->info);

        inorder(root->right);
    }
}

void postorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);

        postorder(root->right);

        printf("\n%d ",root->info);
    }
}

void preorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printf("\n%d ",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

node* create()
{
    node *newnode;
    int x;

    printf("\nEnter data (-1 for no info : )");
    scanf("%d", &x);

    if(x==-1)
    {
        return NULL;
    }
    else
    {
        newnode=(node*)malloc(sizeof(node));

        //Storing info in node
        newnode->info=x;

        //Creating left child using recursion
        printf("\n\nEnter left child of %d : ",x);
        newnode->left=create();

        //Creating right child using recursion
        printf("\n\nEnter right child of %d : ",x);
        newnode->right=create();

        return newnode;
    }
}

int menu()
{
    int ch;

    printf("\n\nTraversal Techniques :\n ");
    printf("\n1. Inorder Traversal");
    printf("\n2. Preorder Traversal");
    printf("\n3. Postorder Traversal");
    printf("\n4. Exit");

    printf("\n\nEnter your choice : ");
    scanf("%d",&ch);

    return ch;
}


void tr_menu(node *root)
{
    int ch;
    while(1)
    {
        ch=menu();

       switch(ch)
        {
            case 1: printf("\n\nInorder Traversal \n");
                    inorder(root);
                    break;
            case 2: printf("\n\nPreorder Traversal \n");
                    preorder(root);
                    break;
            case 3: printf("\n\nPostorder Traversal \n");
                    postorder(root);
                    break;
            case 4: exit(0);
            default:printf("\n\nInvalid Choice !!");
        }
    }
}





