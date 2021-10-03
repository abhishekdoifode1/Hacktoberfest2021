#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *nextNode;
	
};
class stack{
	public:
		Node *top;
	stack(){
		this->top=NULL;
	}
	void push(int value){
		Node *temp = new Node;
		temp->data = value;
		temp->nextNode = NULL;
		if(top = NULL){
			top = temp;
			temp->nextNode = NULL;
		}
		else{
			temp->nextNode = top;
			top=temp;
		}
	}
	void pop(){
		if(top !=NULL){
			Node *temp = top;
			top = top->nextNode;
			delete temp;
		}
		else{
			cout<< "Stack does not exists: "<<endl;
		}
	}
	void display(){
		if(top !=NULL){
			Node *temp = top;
			while(temp != NULL){
				cout<<"DATA: "<<temp->data<<endl;
				temp = temp->nextNode;
			}	
		}
			else{
			cout<< "Stack does not exists: "<<endl;
		}
	}
};
int main(){
	int value;
	stack object;
	bool a = true;
		while (a == true){
		
	cout<<"**************Select from below: ****************"<<endl;
	cout<<"\t \t Press 1 to push data "<<endl;
    cout<<"\t \t Press 2 to pop data "<<endl;
     cout<<"\t \t Press 3 to Display! "<<endl;
    cin>>value;
    switch(value){
    	case 1:
    		cout<<"Enter the data to push in stack: "<<endl;
    		cin>>value;
    		object.push(value);
    		cout<<"The data is pushed successfully!"<<endl;
    		
    		break;
    		
    	case 2:
    		object.pop();
    		cout<<"The data is poped successfully!"<<endl;
		
			break;
			
		case 3:
		object.display();
		break;
		
		default:
		cout<<"\n Oops!! something went wrong!"<<endl;	
	}
    	}
}
