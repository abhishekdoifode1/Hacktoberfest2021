#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max(int a, int b)
{
    return (a>b)?a:b;
}

int maxsubarraysum(int arr[], int n)
{
    if(n==1)
        return arr[0];
    int m=n/2;
    int leftmss=maxsubarraysum(arr,m);
    int rightmss=maxsubarraysum(arr+m, n-m);
    int leftsum = INT_MIN, rightsum = INT_MIN, sum=0;
    for (int i=m; i<n; i++)
    {
        sum+=arr[i];
        rightsum=max(rightsum, sum);
    }
    sum=0;
    for (int i=(m-1); i>=0; i--)
    {
        sum+=arr[i];
        leftsum=max(leftsum, sum);
    }
    int ans=max(leftmss, rightmss);
    return max(ans, (leftsum+rightsum));
}

int main()
{
    int i,num;
    printf("-----------------------------------------------------\n");
    printf("Finding Maximun Subarray Sum using Divide and Conquer\n");
    printf("-----------------------------------------------------\n");
    printf("Enter number of elements: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter numbers: \n");
    for(i=0; i<num; i++)
        scanf("%d",&arr[i]);
    int s = maxsubarraysum(arr, num);
    printf("\nMaximum subarray sum: %d", s);
    return 0;
}