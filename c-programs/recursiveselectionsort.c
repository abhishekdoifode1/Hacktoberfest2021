#include<stdio.h>

void selectionSort(int arr[], int i, int j, int num, int flag)
{
    if(i<num-1)
    {
        if(flag)
            j=i+1;
        if(j<num)
        {
            if(arr[i]>arr[j])
            {
                //swap without third variable
                arr[i]=arr[i]+arr[j];
                arr[j]=arr[i]-arr[j];
                arr[i]=arr[i]-arr[j];
            }
            selectionSort(arr, i, j+1, num, 0);
        }
        selectionSort(arr, i+1, 0, num, 1);
    }
}

int main()
{
    int i,j,num,pos,temp;
    printf("------------------------------------------\n");
    printf("Recursive implementation of Selection Sort\n");
    printf("------------------------------------------\n");
    printf("Enter number of elements: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter numbers: \n");
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    selectionSort(arr, 0, 0, num, 1);
    printf("Sorted order of given numbers is: \n");
    for(i = 0; i < num; i++)
        printf("%d ", arr[i]);
    return 0;
}

