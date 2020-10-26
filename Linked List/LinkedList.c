#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

typedef struct node Node;

void Display(Node *start)
{
    Node* temp=start;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->info);
        temp=temp->next;
    }
}

Node* Create()
{
    Node *new;
    new=(Node*)malloc(sizeof(Node));
    printf("Enter value : ");
    scanf("%d",&new->info);
    new->next=NULL;
    return new;
}

Node* InsertBeg(Node *start)
{
    Node* ptr=Create();
    if(start==NULL)
        start=ptr;
    else
    {
        ptr->next=start;
        start=ptr;
    }
    Display(start);
    return start;
}

void InsertEnd(Node *start)
{
    Node* ptr=Create();
    Node* temp;
    if(start==NULL)
    {
        start=ptr;
    }
    else
    {
       temp=start;
       while(temp->next!=NULL)
            temp=temp->next;
       temp->next=ptr;

    }
    Display(start);
}

void InsertRand(Node* start,int k)
{
    if(k==1)
        start=InsertBeg(start);
    else{
    Node* ptr=Create();
    Node *temp,*temp1;
    temp=start;
    int pos=0;
    while(temp!=NULL)
    {
        pos++;
        if(pos==k-1)
        {
            temp1=temp->next;
            temp->next=ptr;
            ptr->next=temp1;
            break;
        }
        temp=temp->next;
    }
    }
    Display(start);
}

Node* DeleteBeg(Node *start)
{
    Node *temp=start;
    if(start==NULL)
        printf("List out of bounds\n");
    else
    {
        start=start->next;
        free(temp);
        Display(start);
    }

    return start;
}
void DeleteEnd(Node* start)
{
    Node *temp=start,*prev=NULL;
    if(start==NULL)
        printf("List out of bounds\n");
    else
    {
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        free(temp);
        prev->next=NULL;
        Display(start);
    }
}

void DeleteRand(Node *start,int k)
{
    Node *temp,*temp1;
    temp=start;
    int pos=0,pos1=0;
    if(start==NULL)
        printf("List out of bounds\n");
    else{
    while(temp->next!=NULL)
    {
        pos++;
        if(pos==k-1)
        {
            temp1=temp->next;
            temp->next=temp1->next;
            free(temp1);
            break;
        }
    }
    Display(start);}

}
int main()
{
    Node *start,*rear;
    start=NULL;
    rear=NULL;
    int ch,k;
    do
    {
        printf("\n1.Insert at beginning\n2.Insert at kth pos\n3.Insert at end\n4.Delete at beginning\n5.Delete at kth pos\n6.Delete at end\n7.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            start=InsertBeg(start);
            break;
        case 2:
            printf("Enter kth pos : ");
            scanf("%d",&k);
            InsertRand(start,k);
            break;
        case 3:
            InsertEnd(start);
            break;
        case 4:
            start=DeleteBeg(start);
            break;
        case 5:
            printf("Enter pos to be deleted : ");
            scanf("%d",&k);
            DeleteRand(start,k);
            break;
        case 6:
            DeleteEnd(start);
            break;
        case 7:
            printf("BYE\n");
            break;
        default:
            printf("Invalid choice\n");

        }
    }while(ch!=7);
    return 0;
}
