#include<iostream>
#include<queue>
using namespace std;

struct Node{
	char data;
	Node* left;
	Node* right;
};

void Inorder(Node* root){
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

Node* Insert(Node*root, int value)
{
	if(root == NULL)
		{
			Node* temp = new Node;
			temp->data = value;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}
		else if(root->data > value){
			root->left = Insert(root->left, value);
		}
			else if(root->data < value){
				root->right= Insert(root->right, value);
			}
		return root;	
	
	}
int main(){
	Node* root = NULL;
	root = Insert(root, 'S');
	root = Insert(root, 'Q');
	root = Insert(root, 'U');
	root = Insert(root, 'T');
	root = Insert(root, 'R');
	root = Insert(root, 'P');
/*	cout<<"     M ";
	cout<<"    / \";
	cout<<"   B   Q";
	cout<<"  / \   \";
	cout<<"	A   C   Z";
*/
	cout<<endl;
	Inorder(root);
	cout<<endl;
}
