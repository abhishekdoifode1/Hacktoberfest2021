#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

        ~Node(){
            cout << "Deleted " << data << endl;
        }
};

void init_list(Node **head){
    Node* temp_node = NULL;
    int data;
    int size;

    cout << "Enter the size of the list " << endl;
    cin >> size;

    cout << "Enter the node 1" <<endl;
    cin >> data;
    (*head) = new Node();
    (*head)->data = data;

    temp_node = *head;

    for(int i = 1; i < size; i++){
        Node *temp = new Node();
        cout << "Enter the node " << i+1 << endl;
        cin >> data;

        // updating the new node with data
        temp->data = data;
        temp->next = NULL;

        // Updating the previous node
        temp_node->next = temp;

        // changing the temp_node
        temp_node = temp;
    }
}

bool isEmpty(Node *head){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

void printList(Node *head){
    Node *temp = head;
    if(isEmpty(head)){
        cout << "List is empty" << endl;
    }
    for(int i = 0; temp != NULL; i++){
        if(temp->next == NULL){
            cout << temp->data;
            temp = temp->next;
        }
        else{
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
    cout << endl;
}

void getMiddle(Node *head){
    // one pass strategy
    if(head == NULL){
        // its an empty list
        cout << "The list is empty!!" << endl;
        return;
    }
    Node *slow_node = head;
    Node *fast_node = head;
    int count = 0;
    while(fast_node->next != NULL && fast_node->next->next != NULL){
        count++;
        fast_node = (fast_node->next)->next;
        slow_node = slow_node->next;
    }
    cout << "Middle: " << slow_node->data << " at index " << count << endl;
}

void deleteAll(Node **head){
    Node *temp = *head;
    for(int i = 0; temp != NULL; i++){
        Node *temp_t = temp;
        delete(temp);
        temp = temp_t->next;
    }
    *head = NULL;
}
int main(){
    Node *head = NULL;
    // Create a list
    init_list(&head);
    printList(head);
    //Get middle 
    getMiddle(head);

    // Lets make it null
    cout << "Deleted all the elements of the list. Lets try getting the middle node data" << endl;
    deleteAll(&head);
    getMiddle(head);

    cout << "Program exit....cleanup" << endl;
    deleteAll(&head);
    return 0;
}