#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *right;
    struct node *left;
} snode;

snode* newNode(int val){
    snode *temp=(snode*)malloc(sizeof(snode));
    temp->value=val;
    temp->left=temp->right=NULL;
    return temp;
}

snode* insert(snode* node,int val){
    if(node==NULL) return newNode(val);
      if (val<node->value)
         node->left=insert(node->left,val);
      else if (val>node->value)
         node->right=insert(node->right,val);
    return node;
}

void search(struct node *root, int key){
    if (root!=NULL){
       if (root->value==key){
           printf("\nNumber is present in the tree!");
       }
       else if (root->value > key){
           search(root->left, key);
       }
       else{
           search(root->right, key);
       }
    }
    else{
        printf("\nNumber is present in the tree!");
    }
}

int main(){
    snode *root= NULL;
    int arr[7]={30,15,10,12,45,35,52},s,i,c=1;
    root=insert(root,arr[0]);
    for(i=1;i<7;i++){
        insert(root,arr[i]);
    }
    while(c==1){
        printf("Enter the number you wanna find in the tree: ");
        scanf("%d",&s);
        search(root, s);
        printf("\nDo you still wanna continue? 1/0? ");
        scanf("%i",&c);
        //printf("%c",c);
    }
    return 0;
}
