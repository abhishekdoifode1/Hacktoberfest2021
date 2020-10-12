// This program illustrates the concept of Stack Data Structure using linked list.
// Methods for push, pop, displaying the contents of the stack, and searching have been programmed.
// No global variables are used in the implementation of the program.

#include<iostream>
#define MAX 5
using namespace std;

class node
{
public:
    int data;
    node* next;
};


bool isEmpty(node** head) //Checks if the stack is empty or not. Here head refers to tos (top of stack)
{
    if(*head == NULL)
    {
        return true;
    }
    return false;
}

bool isFull(int n)//Checks if the stack is Full or not. Here, n is the current size of the stack
{
    if(n == MAX)
    {
        return true;
    }
    return false;
}

void push(node** head, node* new_node, int n)// head refers to tos(top of stack). 
{
// Double pointer is the pointer to another pointer. 
// So it stores the address of another pointer which, 
// in this case is tos because we need insert into the stack and update the tos.
    if(isFull(n))
    {
        cout << "Overflow!!\n";
    }
    else
    {
        new_node->next = *head;
        *head = new_node;
    }
}

int pop(node** head)
{
    if(isEmpty(head))
    {
        cout << "Underflow!!\n";
        return -1;
    }
    else
    {
        node* temp = *head;
        int item = temp->data;
        *head = temp->next;
        delete temp;
        return item;
    }

}

void display(node** head)
{
    if(isEmpty(head))
    {
        cout << "Underflow!!\n";
    }
    else
    {
        node* temp = *head;
        while(temp != NULL) //Traversing through the stack and printing each element/data stored at respective index.
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

}

void search(node** head, int pos, int n)//Search method: head refers to tos(top of stack), pos is the position where the search is to be performed. n is the current size of the stack.
{

    if(isEmpty(head)) // Checking if the stack is empty or not.
    {
        cout << "Underflow!!\n";
        return;
    }
    node* tempTos = NULL; // Creating a temporary stack in which we would push the elements after popping from the original one until position pos is not found.
    int temp_size = 0;
    int p = 0;
    if(pos >= n) // If the input index is out of range where no value exists, print "Not found!!"
    {
        cout << "Not Found!!\n";
    }
    else
    {
        while(p <= pos) // until p<=pos we need to perform following operations
        {
            int popped = pop(head); // pop from the original stack
            n--;
            node* temp_node = new node(); //creating a new node to be pushed into the temporary stack
            temp_node->data = popped; 
            push(&tempTos, temp_node, temp_size); // push into the temporary stack
            temp_size++; // increment the size of temporary stack
            p++; // increment p
        }
         cout << "Data at the required index: " << tempTos->data << endl; // at this point, we have popped and pushed all the elements of stack into the temporary stack.
        int i=0;
        while(i<temp_size) // RECONSTRUCTION OF ORIGINAL STACK
        {
            int popped = pop(&tempTos); // Pop from the temporary stack
            node* new_node = new node();
            new_node->data = popped;
            push(head, new_node, n);//Push into the original stack.
            i++;
        }
    }
}
//Driver method.
int main()
{
    node* tos = NULL;
    int n=0,choice;
    while(1)   // MAIN MENU
    {
        cout << "\n1.Push\n";
        cout << "\n2.Pop\n";
        cout << "\n3.Display\n";
        cout << "\n4.Search\n";
        cout << "\n5.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                node* new_node = new node();
                int item;
                cout << "Enter the element you want to push into the stack: ";
                cin >> item;
                new_node->data = item;
                push(&tos, new_node, n);
                n++;
                break;
            }
            case 2:
            {
                int popped = pop(&tos);
                cout << popped << endl;
                n--;
                break;
            }
            case 3:
            {
                display(&tos);
                break;
            }
            case 4:
            {
                int pos;
                cout << "Enter the position at which you want to search: ";
                cin >> pos;
                search(&tos, pos, n);
                break;
            }
            case 5:
            {
                return 0;
            }
            default:
                cout << "Enter the valid choice!!\n";
        }
    }
}
