#include <stdio.h>

void insertionSort(int arr[], int i, int n)
{
	int value=arr[i];
	int j=i;
	while (j>0 && arr[j-1]>value)
	{
		arr[j]=arr[j-1];
		j--;
	}
	arr[j]=value;
	if (i+1<=n)
        insertionSort(arr, i+1, n);
}

int main()
{
    int i,num;
    printf("------------------------------------------\n");
    printf("Recursive implementation of Insertion Sort\n");
    printf("------------------------------------------\n");
    printf("Enter number of elements: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter numbers: \n");
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
	insertionSort(arr, 1, num - 1);
    printf("Sorted order of given numbers is: \n");
	for (int i = 0; i < num; i++)
		printf("%d ", arr[i]);
	return 0;
}