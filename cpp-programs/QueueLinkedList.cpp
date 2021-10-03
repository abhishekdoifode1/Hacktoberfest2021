#include<iostream.h>
#include<conio.h>
#include<stdio.h>

 struct node
 { float marks;
   char name[20];
   node *link;   };

 class queue
 {  node *front,*rear;

    public:queue()
	  { front=rear=NULL; }

	  void inque()
	  { node *p1;
	    p1=new node;
	    cout<<"\nEnter marks:";
	    cin>>p1->marks;
	    cout<<"Enter name:";
	    gets(p1->name);
	    p1->link=NULL;
	    
      if(front==NULL)
	       front=rear=p1;
	    else
	    { rear->link=p1;
		     rear=p1;   }
	    
      cout<<"\nInsertion successfull";  }

void disque()
{   if(front==NULL)
		  cout<<"\nQueue is empty";
		else
	  { node *temp;
		  temp=front;
		  cout<<"\nName: ";
		  while(temp!=NULL)
		  { cout<<temp->name<<"\t";
		    temp=temp->link;  }
		  temp=front;
		 cout<<"\nMarks: ";
		 while(temp!=NULL)
		 { cout<<temp->marks<<"\t";
		   temp=temp->link;  }	  }       }

void delque()
{ if(front==NULL)
	cout<<"\nQueue is empty";
	else
	{ node *temp;
	  temp=front;
	  front=front->link;
	  cout<<temp->name<<" is deleted";
	  delete temp;   }            }      };
 
 void main()
 { clrscr();
   char ch,ans;
   queue n1;
   do
   { clrscr();
     cout<<"\n\tMENU\nA.Push\nB.Pop\nC.Display";
     cout<<"\nEnter your choice(A/B/C):";
     cin>>ch;
     switch(ch)
     { case 'A':
       case 'a':n1.inque();break;
       case 'B':
       case 'b':n1.delque();break;
       case 'C':
       case 'c':n1.disque();break;
       default:cout<<"\nWrong choice";  }
 cout<<"\n\nDo you wish to continue(Y/N):";
 cin>>ans;  }while(ans=='y'||ans=='Y');

getch();  }
