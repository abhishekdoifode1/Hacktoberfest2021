#include<iostream>
#include<queue>
using namespace std;

struct Node{
	char data;
	Node* left;
	Node* right;
};

void Preorder(Node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
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
	root = Insert(root, 'M');
	root = Insert(root, 'B');
	root = Insert(root, 'Q');
	root = Insert(root, 'Z');
	root = Insert(root, 'A');
	root = Insert(root, 'C');
/*	cout<<"     M ";
	cout<<"    / \";
	cout<<"   B   Q";
	cout<<"  / \   \";
	cout<<"	A   C   Z";
*/
	cout<<endl;
	Preorder(root);
	cout<<endl;
}
