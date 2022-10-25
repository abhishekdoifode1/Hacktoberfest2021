#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *getNewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
};

bool search(Node *root, int data)
{
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (data <= root->data)return search(root->left, data);
    else return search(root->right, data);
};

int main()
{
    Node *root = NULL; // empty tree create
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);

    int num;
    cout<<"Enter Number to search :";
    cin>>num;
    if (search(root, num) == true) cout<<"Found : "<<num<<endl;
    else cout<<"Not Found : "<<num<<endl;
};
