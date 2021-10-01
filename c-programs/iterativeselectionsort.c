#include<stdio.h>
int main()
{
    int i, j, num, pos;
    printf("------------------------------------------\n");
    printf("Iterative implementation of Selection Sort\n");
    printf("------------------------------------------\n");
    printf("Enter number of elements: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter numbers: \n");
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    for(i=0; i<num-1; i++)
    {
        pos=i;
        for(j=i+1; j<num; j++)
            if(arr[pos]>arr[j])
                pos=j;
        if(pos!=i)
        {
            arr[i]=arr[i]+arr[pos];
            arr[pos]=arr[i]-arr[pos];
            arr[i]=arr[i]-arr[pos];
        }
    }
    printf("Sorted order of given numbers is: \n");
    for(i=0; i<num; i++)
        printf("%d ", arr[i]);
    return 0;
}