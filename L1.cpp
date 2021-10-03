#include<stdio.h>
void descen_array(int [],int);
void inser_array(int [],int*);
void del_big_array(int [],int*);
void prin_array(int [],int);

void main()
{
	int n,A[30];
	prinf("Enter n");
	scanf("%d",&n);
	prinf("Enter the elements");
	for(int i=0;i<n;i++)
	scanf("%d",&A[i]]);
	
	decsen_array(A,n);
	inser_array(A,&n);
	del_big_array(A,&n);
	prin_array(A,n);
	
	return 0;
}

void descen_array(int b[],int *n1){
	int i,j,temp;
	for(i=0;i<n1;i++){
		for(j=i+1;j<n1;j++){
			if(b[i]<b[j]){
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	printf("Array in dscending order \n");
	for(i=0;i<n1;i++){
		
		printf("%d ",b[i]])
	}
}
