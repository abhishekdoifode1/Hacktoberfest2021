#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

};

Node* front = NULL;
Node* rear = NULL;

void Enqueue(int value)
{
    struct Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    struct Node* temp = front;
    if (front == rear)
    {
        front = rear = NULL;

    }
    else
    {
        front = front -> next;

    }
    delete(temp);
}

void Display()
{
    Node* Temp = NULL;
    Temp = front;

    if (front == NULL && rear==NULL)
    {
        cout << "queue is empty!" << endl;
    }
    else
    {
        cout << endl << "Queue is :" << endl;
        while (Temp!=NULL)
        {
            cout << Temp->data << "   " << endl;
            Temp = Temp->next;
        }
      
        cout << endl;
    }
}

int main()
{
    Enqueue(21);
    Enqueue(100);
    Enqueue(11);
    Enqueue(2);
    Enqueue(121);
    Enqueue(4);
    Display();

    Dequeue();
    Dequeue();
    Dequeue();
    Display();

    cout << "The Front is:";
    cout << front->data << endl;
    cout << "The Rear is: ";
    cout << rear->data << endl;
    return 0;
}

