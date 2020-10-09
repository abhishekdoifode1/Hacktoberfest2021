#include<stdio.h>
int main()
{
    int i, j, num;
    printf("---------------------------------------\n");
    printf("Iterative implementation of Bubble Sort\n");
    printf("---------------------------------------\n");
    printf("Enter number of elements: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter numbers: \n");
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    for (i=0; i<num-1; i++)
        for (j=0; j<num-i-1; j++)
            if (arr[j]>arr[j+1])
            {
                //swap without third variable
                arr[j]=arr[j]+arr[j+1];
                arr[j+1]=arr[j]-arr[j+1];
                arr[j]=arr[j]-arr[j+1];
            }
    printf("Sorted order of given numbers is: \n");
    for(i=0;i<num;i++)
        printf("%d ",arr[i]);
    return 0;
}