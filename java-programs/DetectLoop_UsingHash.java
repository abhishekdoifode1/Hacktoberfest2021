import java.util.*;
public class SLL {
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
void DetectLoop(Node head) {
	Node temp=head;
	Node prev=null;
	Set<Node> hash=new HashSet<Node>();
	while(temp!=null) {
		if(hash.contains(temp)) {
			System.out.println("LOOP DETECTED! " +"This "+ prev.data+" node"+" is pointing back to "+temp.data);
			prev.next=null;
			System.out.println("LOOP REMOVED");
			return;
			
		}
		hash.add(temp);
		prev=temp;
		temp=temp.next;
	}System.out.println("NO LOOP DETECTED");return;
}
void display(Node head) {
	
	if(isEmpty()){
		Node temp=head;
		while(temp!=null) {
			System.out.println(temp.data);
			temp=temp.next;
		}
	}
else{
System.out.println("Nothing to display");
}
}
	public static void main(String[] args){
		SLL sll=new SLL();
		sll.appendNode(5);
		sll.appendNode(10);
		sll.appendNode(15);
		sll.appendNode(20);
		sll.appendNode(25);
		sll.head.next.next.next.next=sll.head.next.next;
		sll.DetectLoop(sll.head);
	}
}