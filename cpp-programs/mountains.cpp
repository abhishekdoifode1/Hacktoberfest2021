#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int highestMountain(vector<int> arr)
{
	int n =arr.size();
	int largest=0;
	
	for(int i = 1; i <= n-2;)
	{
		if(arr[i] > arr[i+1] && arr[i] > arr[i-1])
		{
			int c = 1;
			int j = i;
			while(j>=1 && arr[j] > arr[j-1])
			{
				c++;
				j--;
			};
			while(arr[i] > arr[i+1] && i<=n-2)
			{
				i++;
				c++;
			};
			
			largest = max(largest,c);
		}
		else
		{
			i++;
		}
		
	}
	return largest;
}

int main()
{
	vector<int> arr = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
	
	cout<<highestMountain(arr);
	
	return 0;
}
