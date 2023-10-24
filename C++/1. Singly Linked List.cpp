#include<iostream>
using namespace std;
struct Node{
	Node* nextNode = NULL;
	int data;
};
class linkedList{
public:
		Node* head, *tail;
	
		linkedList(){
			this->head = NULL;
	        this->tail = NULL;
		};
	void addNode(int value){
		Node* temp = new Node;
		temp->data=value;
		temp->nextNode = NULL;
		if(head==NULL){
			head = temp;
			tail =temp;
			cout<<"ENTERED DATA: "<<value<< endl;
			
		}
		else{
			tail->nextNode = temp;
			tail = tail->nextNode;
		
		}	
}
	void display(Node* node){
		if(node == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << node->data << endl;
            display(node->nextNode);
        }
    }

	void insert_at_front(int value){
		Node* temp = new Node;
		temp->data = value;
		temp->nextNode=head;
		head=temp;
		
	}
	void insert_at_end(int value){
		Node* temp = new Node;
		temp->data = value;
		temp->nextNode = NULL;
		if(head==NULL){
			head = temp;
			tail = temp;
		}
		else{
			tail->nextNode = temp;
			tail = tail->nextNode;
		}
	}
};

int main(){
	int value;
	linkedList object;
	cin>>value;
	object.addNode(value);
	object.addNode(4);
	object.addNode(5);
	object.display(object.head);
	cin>>value;
	object.insert_at_end(value);
	cin>>value;
	object.insert_at_front(value);
	object.display(object.head);
}

