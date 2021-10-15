#include<stdio.h>
#include<stdlib.h>

struct array{
    int *A;
    int size;
};

void SelectionSort(int B[],int size){
    
    for(int i=0;i<size;i++){
    int k,j;
    k=i;    
    int x=B[i];
    for(int j=i;j<size;j++){
            if(B[j]<x){
                x=B[j];
                k=j;
            }
        }
        int temp=B[i];
        B[i]=B[k];
        B[k]=temp;
    
    }

}

int main(){
int B[]= {11,13,7,12,16,9,24,5,10,3,__INT32_MAX__};

SelectionSort(B,10);

for (int i = 0; i < 10; i++)
{
    printf("%d ",B[i]);
}

return 0;

}