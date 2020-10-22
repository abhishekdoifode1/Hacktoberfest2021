#include <iostream>
#include <vector>
using namespace std;

void buysellstock(int arr[],int n)
{
   int i;
   vector<int> mins;
   vector<int> maxs;
   if(arr[0]<arr[1])
   mins.push_back(0);
   for(i=1;i<n-1;i++)
   if(arr[i]<arr[i+1] && arr[i]<arr[i-1])
   mins.push_back(i);
   
  
   for(i=1;i<n-1;i++)
   if(arr[i]>arr[i+1] && arr[i]>arr[i-1])
   maxs.push_back(i);
   if(arr[n-1]>arr[n-2])
   maxs.push_back(n-1);
   
   if(!mins.size() && !maxs.size())
   cout<<"No Profit"<<endl;
   else{
   for(i=0;i<mins.size();i++)
   cout<<"("<<mins[i]<<" "<<maxs[i]<<")"<<" ";
   cout<<endl;}

}


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int i, n;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
        cin>>arr[i]; 
        buysellstock(arr,n);
        
    }
	return 0;
}
