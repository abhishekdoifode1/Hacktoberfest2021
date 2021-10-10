//to create a linear queue using array
#include <stdio.h>
#include <stdlib.h>
int a[5];
int front = -1, rear = -1;
void enqueue()
{
    if (rear == 4)
    {
        printf("\n Overflow ");
        return;
    }
    else
    {
        int data;
        printf("\n Enter the data : ");
        scanf("%d", &data);
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear += 1;
        }
        a[rear] = data;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Underflow ");
        return;
    }
    else
    {
        int item;
        if (front == rear)
        {
            item = a[front];
            front = rear = -1;
        }
        else
        {
            item = a[front];
            front += 1;
        }
        printf("\n Dequeue item : %d", item);
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Underflow ");
        return;
    }
    else
    {
        printf("|");
        for (int i = front; i <= rear; i++)
            printf(" %d ", a[i]);
        printf("|");
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n 1.To Enqueue ");
        printf("\n 2.To Dequeue ");
        printf("\n 3.Display ");
        printf("\n 4.Exit ");

        printf("\n Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n Harmehar Kaur (CSE-1 04613202720)\n");
            exit(0);
        }
    }
}