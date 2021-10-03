#include <bits/stdc++.h>
using namespace std;

int coolness_measure(int a);
int binary_conversion(int n);

int main()
{
    int t,r,k,cool=0;
    cin>>t;
    for(int i=1;i<=t;i++)
    {   cool=0;
        cin>>r>>k;
        for(int j=1;j<=r;j++)
        {
           if(binary_conversion(j)>=k)
           cool++;
        }
         cout<<cool<<endl;
    }
   
    return 0;
}



int binary_conversion(int n)
{
    int binarynum[32];
    int i=0,count=0;
    while(n>0)
    {
        binarynum[i]=n%2;
        n=n/2;

    if(binarynum[i]==1 && binarynum[i-1]==0 && binarynum[i-2]==1 && i-2>=0)
    {
        count++;
    }
        i++;
    }

return count;
}