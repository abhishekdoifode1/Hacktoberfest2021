#include<stdio.h>
void bubbleSort(int arr[], int num)
{
    int i, j;
    i=num;
    if(i>0)
    {
        for(j=0; j<num-1; j++)
            if(arr[j]>arr[j+1])
            {
                //swap without third variable                
                arr[j]=arr[j]+arr[j+1];
                arr[j+1]=arr[j]-arr[j+1];
                arr[j]=arr[j]-arr[j+1];
            }
        BubbleSortRecursion(arr, num-1);
    }
    else
        return;    
}

int main()
{
    int i,j,num,temp;
    printf("---------------------------------------\n");
    printf("Recursive implementation of Bubble Sort\n");
    printf("---------------------------------------\n");
    printf("Enter number of elements: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter numbers: \n");
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    BubbleSortRecursion(arr,num);
    printf("Sorted order of given numbers is: \n");
    for(i=0;i<num;i++)
        printf("%d ",arr[i]);
    return 0;
}