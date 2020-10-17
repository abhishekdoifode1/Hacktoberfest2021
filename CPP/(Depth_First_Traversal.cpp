/*
Tree traversal (Depth First Traversal)
Inorder Traversal
Preorder Traversal
Postorder Traversal
*/

#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node(int item)
    {
        data=item;
        left=right=NULL;
    }
    Node *right,*left;
};
void Inorder(Node* node)
{
    if(node==NULL)
        return;
    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}
void preorder(Node * node)
{
    if(node==NULL)
        return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);

}
void postorder(Node *node)
{
    if(node==NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";

}

int main()
{
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    cout<<"Inorder Traversal: ";
    Inorder(root);
    

    cout<<"\nPreorder Traversal: ";
    preorder(root);

    cout<<"\nPostorder Traversal: ";
    postorder(root);

    return 0;
}
