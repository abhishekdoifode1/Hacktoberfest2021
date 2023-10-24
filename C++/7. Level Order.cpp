#include<iostream>
#include<queue>
using namespace std;

struct Node{
	char data;
	Node* left;
	Node* right;
};

void LevelOrder(Node *root){
	if(root==NULL){
		return;
	}
	queue<Node*> Q;
	Q.push(root);
	while(!Q.empty()){
		Node* current = Q.front();
		cout<<current->data<<" ";
		if(current->left != NULL){
			Q.push(current->left);
		}
		if(current->right !=NULL){
			Q.push(current->right);
		}
		Q.pop();
	}
	
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
	cout<<"******LevelOrder*******";
	cout<<endl;
	LevelOrder(root);
	cout<<endl;
}
