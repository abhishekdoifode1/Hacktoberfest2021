package testing;
import java.util.*;
public class SinglyLinkedListII {
Node head=null;
class Node{
	int data;
	Node next;
	Node(int data){
		this.data=data;
		this.next=null;
				  }
			 }
void appendNode(int data) {
	Node newnode=new Node(data);
	Node temp=head;
	if(temp==null) {
		newnode.next=head;
		head=newnode;
	}else {
		while(temp.next!=null) {
			temp=temp.next;
		}
		newnode.next=temp.next;
		temp.next=newnode;
	}
}
boolean isEmpty() {
	Node temp=head;
	if(temp==null) {
		return false;
	}else {return true;}

}
void reverseLoop() {
	Node prevnode=null;
	Node current=head;
	Node nextnode=null;
	while(current!=null) {
		nextnode=current.next;
		current.next=prevnode;
		prevnode=current;
		current=nextnode;
	}head=prevnode;
}

int length(Node head) {
	Node temp=head;
	if(isEmpty()) {
		int count=0;
		while(temp!=null) {
			count++;temp=temp.next;
		}return count;
	}else {return -1;}
}


void display() {
	
	if(isEmpty()){
		Node temp=head;
		while(temp!=null) {
			System.out.println(temp.data);
			temp=temp.next;
		}
	}else {System.out.println("Nothing to display");}
}
	public static void main(String[] args){
		SinglyLinkedListII sll=new SinglyLinkedListII();
		sll.appendNode(5);
		sll.appendNode(10);
		sll.appendNode(15);
		sll.appendNode(20);
		sll.appendNode(25);
		sll.reverseLoop();
		sll.display();

	}
}