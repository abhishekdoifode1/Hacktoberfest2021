#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    char data;
    Node* next;
    Node(char x){
        data=x;
        next=NULL;
    }
};

Node *reverseList(Node *head){
    if(head==NULL||head->next==NULL)return head;
    Node *rest_head=reverseList(head->next);
    Node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

bool isPalindrome(Node *head){
        if(head==NULL)return true;
        Node *slow=head,*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *rev=reverseList(slow->next);
        Node *curr=head;
        while(rev!=NULL){
            if(rev->data!=curr->data)
                return false;
            rev=rev->next;
            curr=curr->next;
        }
        return true;
    }


int main() 
{ 
	Node *head=new Node('g');
	head->next=new Node('f');
	head->next->next=new Node('g');
	if(isPalindrome(head))
	    cout<<"Yes";
	else
	    cout<<"No";
	return 0;
} 
