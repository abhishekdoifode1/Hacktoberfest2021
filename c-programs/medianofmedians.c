#include<stdio.h>
#include<limits.h>

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int sortAndFindMedian(int arr[], int num)
{
    for (int i=1; i<num; i++)
	{
		int value=arr[i];
		int j=i;
		while (j>0 && arr[j-1]>value)
		{
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=value;
	}
    if(num%2==0)
        return((arr[num/2]+arr[num/2-1])/2.0);
    else
        return arr[num/2];
}

int partition(int arr[], int low, int high, int x) 
{ 
    int i; 
    for (i=low; i<high; i++) 
        if (arr[i]==x) 
           break; 
    swap(&arr[i], &arr[low]); 
    i = low; 
    for (int j=low; j<=high-1; j++) 
    { 
        if (arr[j]<=x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[high]); 
    return i; 
}

int deterministicSelect(int arr[], int low, int high, int k)
{
    if(k>0 && k<=high-low+1)
    {
        int n=high-low+1;
        int i;
        int median[(n/4)/5];
        for(i=0; i<n/5; i++)
            median[i]=sortAndFindMedian(arr+low+i*5, 5);
        if(i*5<n)
        {
            median[i]=sortAndFindMedian(arr+low+i*5, n%5);
            i++;
        }

        int medianOfMedians = (i==1) ? median[i-1] : deterministicSelect(median, 0, i-1, i/2);
        int position=partition(arr, low, high, medianOfMedians);
        /////
        if(position==k)
            return medianOfMedians;
        else if (k<position)
            return deterministicSelect(arr, low, position-1, k);
        return deterministicSelect(arr, position+1, high, k-position);
    }
    else
    {
        printf("\nOrder statistic larger than number of elements in array!");
        return INT_MAX;
    }
    
}

int main()
{   
    int i, num, orderStatistic;
    printf("-------------------------------------------------------------------------------\n");
    printf("Finding i'th order statistic in linear time using 'Median of Medians' algorithm\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("Enter number of elements: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter numbers: \n");
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    printf("Enter order statistic (i):  ");
    scanf("%d", &orderStatistic);
    printf("\nThe i'th smallest element in the array is: %d.", deterministicSelect(arr, 0, num-1, orderStatistic));
    return 0;
}