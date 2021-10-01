#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
} nd;
nd *start;
int count(){
    nd *ptr;
    ptr=start;
    int c=0;
    while(ptr->link!= start){
        c++;
        ptr=ptr->link;
    }
    c++;
    return c;
}
void insert_front(){
    nd *temp;
    temp=(nd*)malloc(sizeof(nd));
    printf(" Enter the data : ");
    scanf("%d",&temp->data);
    if(start==NULL){
        start=temp;
        temp->link=start;
    }
    else{
        nd *ptr;
        ptr=start;
        while(ptr->link!=start)
            ptr=ptr->link;
        temp->link=start;
        ptr->link=temp;
        start=temp;
    }
}

void insert_last(){
    nd *temp;
    temp=(nd*)malloc(sizeof(nd));
    printf(" Enter the data : ");
    scanf("%d",&temp->data);
    if(start==NULL){
        start=temp;
        temp->link=start;
    }
    else{
        nd *ptr;
        ptr=start;
        while(ptr->link!=start)
            ptr=ptr->link;
        temp->link=ptr->link;
        ptr->link=temp;
    }
}

void insert_middle(){
    if(start==NULL)
        printf("\n E M P T Y");
    else{
        int f=count(); 
        int pos;
        printf(" Enter the position : ");
        scanf("%d",&pos);
        if(pos==1)
            insert_front();
        else if(pos<=f){
            nd *ptr;
            ptr=start;
            int c=1;
            while(ptr->link!=start){
                if(c==pos-1)  
                    break;
                ptr=ptr->link;
                c++;
            }
            nd *temp;
            temp=(nd*)malloc(sizeof(nd));
            printf(" Enter the data : ");
            scanf("%d",&temp->data);
            temp->link=ptr->link;
            ptr->link=temp;
        }
        else
            printf(" Position not available ");
    }
}

void search(){
    if(start==NULL)
        printf("\n E M P T Y");
    else{
        int item;
        printf(" Enter search item : ");
        scanf("%d",&item);
        nd *ptr;
        ptr=start;
        int c=1;
        while(ptr->link!= start){
            if(ptr->data==item){
                printf("\n Element Found at : %d",c);
                c=-1;
                break;
            }
            c++;
            ptr=ptr->link;
        }
        if(item==ptr->data&&c!=-1)
            printf("\n Element Found at : %d",c++);
        else if(c==1)
            printf("\n Item not found");
    }
}

void delete_first(){
    if(start==NULL)
        printf("\n U N D E R F L O W");
    else{
        printf("\n Deleted : %d",start->data);
        if(count()==1)
            start=NULL;
        else{
            nd *ptr;
            ptr=start;
            while(ptr->link!=start)
                ptr=ptr->link;
            start=start->link;
            ptr->link=start;
        }
    }
}

void delete_end(){
    if(start==NULL)
        printf("\n U N D E R F L O W");
    else{
        if(count()==1)
        {
            printf("\n Deleted : %d",start->link->data);
            start=NULL;
        }
        else{
            nd *ptr;
            ptr=start;
            while(ptr->link->link!=start)
                ptr=ptr->link;
            printf("\n Deleted : %d",ptr->link->data);
            ptr->link=start;
        }
    }
}
void delete_middle(){
    if(start==NULL)
        printf("\n U N D E R F L O W");
    else{
        int f=count();
        int i;
        printf(" Enter index : ");
        scanf("%d",&i);
        if(i==1)
            delete_first();
        else if(i<f){
            nd *ptr;
            ptr=start;
            int c=1;
            while(ptr!=NULL){
                if(c+1==i)
                    break;
                ptr=ptr->link;
                c++;
            }
            printf("\n Delete Element : %d",ptr->link->data);
            ptr->link=ptr->link->link;
        }
        else if(i==f)
            delete_end();
        else
            printf("\n Index Unavailable ");
    }
}
void display(){
    if(start==NULL)
        printf("\n L I S T  E M P T Y");
    else{
        nd *ptr;
        ptr=start;
        int c=1;
        while(ptr->link!= start){
            printf("\n Element %d : %d",c++,ptr->data);
            ptr=ptr->link;
        }
        printf("\n Element %d : %d",c++,ptr->data);
    }
}
void display_reverse(){
    
}
int main()
{
	int ch;
	start=NULL;
	while(1)
	{
		printf("\n\n 1 for Insert Front");
		printf("\n 2 for Insert Last");
        printf("\n 3 for Insert Middle");
        printf("\n 4 for Search Element");
		printf("\n 5 for Delete First ");
        printf("\n 6 for Delete at Index ");
        printf("\n 7 for Delete Last ");
        printf("\n 8 for Display ");
		printf("\n 9 for Exit ");
		printf("\n Enter the choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			insert_front();
			break;
			
			case 2:
			insert_last();
			break;

            case 3:
            insert_middle();
            break;

            case 4:
            search();
            break;
			
			case 5:
			delete_first();
			break;

            case 6:delete_middle();
            break;

            case 7:
            delete_end();
            break;

            case 8:
            display();
            break;

			case 9:
			exit(1);
		}
	}
    return 0;
}