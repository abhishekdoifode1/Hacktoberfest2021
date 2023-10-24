#include<iostream>
using namespace std;
int NON = 0;
struct Node{
	int data;
	Node* prevNode;
	Node* nextNode;
};
class DoublyLL{
	public:
		Node* head, *tail;
	DoublyLL(){
		this->head = NULL;
		this->tail = NULL;
	}
	void add_at_end(int value){
		Node* t1 = new Node;
		Node *temp = new Node;
		temp->data = value;
		temp->nextNode=NULL;
		temp->prevNode=NULL;
		if(head=NULL){
			head= temp;
			tail = temp;
			
		}
		else{
			while(t1->nextNode=NULL){
			t1 = t1->nextNode;
			}
			t1->nextNode = temp;
			temp->prevNode = t1;
			temp->nextNode =NULL;
		}
	}
	void add_at_front(int value){
		Node *temp = new Node;
		temp->data = value;
		temp->nextNode=NULL;
		temp->prevNode=NULL;
		if(head=NULL){
			head= temp;
			tail = temp;
			
		}
		else{
			temp->nextNode = head;
			head->prevNode = temp;
			temp= head;
		}
		
	}
	void add_certain_pos(int value, int pos){
		Node *t1 = new Node;
		Node *t2 = new Node;
		Node *temp = new Node;
		temp->data = value;
		temp->prevNode =NULL;
		temp->nextNode = NULL;
		
		for(int i =0 ; i<pos ; i++){
			t1=t2;
			t2=t2->nextNode;
		}
		t1->nextNode =temp;
		temp->prevNode = t1;
		temp->nextNode = t2;
		t2->prevNode = temp;
		
	}
	void display(){
		Node* node = new Node;
		node = head;
		if(node == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
        	for(int i =0 ; i<NON ; i++){
            cout << node->data << endl;
            node=node->nextNode;
            
        }
    }
}
			
};
int main(){
	int value, pos;
	DoublyLL object;
	bool a = true;
		while (a == true){
		
	cout<<"**************Select from below: ****************"<<endl;
	cout<<"\t \t Press 1 to insert a node at front! "<<endl;
    cout<<"\t \t Press 2 to insert a node at end! "<<endl;
    cout<<"\t \t Press 3 to insert a node at any certain place! "<<endl;
    cout<<"\t \t Press 4 to Display! "<<endl;
    cin>>value;
    switch(value){
    	case 1:
    		cout<<"Enter the data to place in node: "<<endl;
    		cin>>value;
    		object.add_at_front(value);
    		cout<<"The data is entered successfully!"<<endl;
    		NON++;
    		break;
    		
    	case 2:
    		cout<<"Enter the data to place in node: "<<endl;
    		cin>>value;
    		object.add_at_end(value);
    		cout<<"The data is entered successfully!"<<endl;
			NON++;
			break;
			
		case 3:
			cout<<"Enter the data to place in node: "<<endl;
    		cin>>value;
    		cout<<"Enter the position where you want to place data: "<<endl;
    		cin>>pos;
    		object.add_certain_pos(value, pos);
    		cout<<"The data is entered successfully!"<<endl;
			NON++;
			break;
			
		case 4:
		object.display();
		break;
		default:
		cout<<"\n See you soon!";	
	}
    	}
    return 0;
}

