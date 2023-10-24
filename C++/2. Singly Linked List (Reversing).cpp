#include<iostream>
using namespace std;
int NON = 0;
struct Node{
	int data;
	Node *nextNode;
};
class Reverse{
	public:
	Node *head, *tail;
	
		Reverse(){
		this->head = NULL;
		this->tail =NULL;
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
		void display(){
			Node* node = new Node;
	 if(node == NULL){
	 
		
		    cout << node->data << endl;
		    node = node->nextNode;
            display();
        }
        
       
    }
    // ITERATIVE METHODE//
/*
	void ReverseI(){
		Node *prev =new Node;
	Node *next = new Node;
		Node *temp= new Node;
		temp = head;
		prev = NULL;
		
		while(temp !=NULL){
			next = temp->nextNode;
			temp->nextNode=prev;
			prev = temp;
			temp = next;
		}
		head = prev;
	}
	*/
	//RECURSION METHODE//
	void ReverseR(Node *p){
		if(p->nextNode ==NULL){
			head = p;
		}
		ReverseR(p->nextNode);
		Node *q = new Node;
		q= p->nextNode;
		q->nextNode = p;
		p->nextNode = NULL;
		
			}
};
int main(){

int value, pos;
	Reverse object;
	bool a = true;
		while (a == true){
		
	cout<<"**************Select from below: ****************"<<endl;
	cout<<"\t \t Press 1 to insert a node at front! "<<endl;
    cout<<"\t \t Press 2 to insert a node at end! "<<endl;
    cout<<"\t \t Press 3 to Display! "<<endl;
    cout<<"\t \t Press 4 to reverse nodes! "<<endl;
    cin>>value;
    switch(value){
    	case 1:
    		cout<<"Enter the data to place in node: "<<endl;
    		cin>>value;
    		object.insert_at_front(value);
    		cout<<"The data is entered successfully!"<<endl;
    		NON++;
    		break;
    		
    	case 2:
    		cout<<"Enter the data to place in node: "<<endl;
    		cin>>value;
    		object.insert_at_end(value);
    		cout<<"The data is entered successfully!"<<endl;
			NON++;
			break;
			
		case 3:
		object.display();
		break;
		
		case 4:
			object.ReverseR(object.head);
			//object.ReverseI();
			break;
		default:
		cout<<"\n See you soon!"<<endl<<endl<<endl;	
	}
    	}
    return 0;
}
