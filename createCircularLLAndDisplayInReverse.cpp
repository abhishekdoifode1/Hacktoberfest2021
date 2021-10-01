#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node * head = NULL;

void traverse(struct Node *head)
{
    struct Node *temp = head;

    do{
        cout << temp->data <<endl;
        temp = temp->next;
    } while (temp != head);
}

void backwardPrint(struct Node *list) {
   if(list->next == head) {
      cout<<list->data<<endl;
      return;
   }
   backwardPrint(list->next);
   cout<<list->data<<endl;
   
}

void insertAtEnd(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        struct Node *p = head;
        while (p->next != head){
            p = p->next;
        }

        p->next = newNode;
        newNode->next = head;
    }
}

int main(){
    
    insertAtEnd(1);
    insertAtEnd(41);
    insertAtEnd(6);
    insertAtEnd(2);

    traverse(head);
    cout<<endl;

    backwardPrint(head);
    cout<<endl;


    return 0;
}
