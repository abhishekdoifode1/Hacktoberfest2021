#include<stdio.h>

void swap(int *p,int *q){
    int o=*p;
    *p=*q;
    *q=o;
}

int partition(int arr[],int start,int end){
    int pivot=arr[end],i= start-1,index=start;
    for(i=start;i<end;i++){
        if(arr[i]<pivot){
            swap(&arr[index],&arr[i]);
            index++;
        }
    }
    swap(&arr[end],&arr[index]);
    return (index);
}

void quicksort(int arr[],int start, int end){
    if (start<end){
        int pIndex=partition(arr,start,end);
        quicksort(arr,start,pIndex-1);
        quicksort(arr,pIndex+1,end);
    }
}

void printList(int arr[], int size){
    int i;
    for(i=0;i<size;i++)
     printf("%d  ",arr[i]);
}

int main(){
    int n,i;
    printf("Enter the number of values to be sorted and the values, each separated by space\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
     scanf("%d",&arr[i]);
    quicksort(arr,0,n);
    printf("\nSorted order of values:-\n");
    printList(arr,n);
    printf("\n\n");
    return 0;
}