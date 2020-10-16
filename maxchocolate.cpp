#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int M,max=0,count1=0;
    int mincho=0;
    cin>>M;
    int A[M],B[M],a[M];
    for(int i=0;i<M;i++)
    {
        cin>>A[i]>>B[i];
        a[i]=A[i];
    }
 
    for(int i=0;i<M;i++)
    {
        count1=0;
        for(int j=0;j<M;j++)
        {
        if(B[j]>=a[i] && A[j]<=a[i])
        {
        count1++;
        }
        }
        if(max<=count1)
        {
        

        if(max<count1)
        mincho=a[i];
        if(max=count1)
        {
        if(mincho>a[i])
        mincho=a[i];
        }

        max=count1;
        }
        

    }
    cout<<mincho<<endl<<max;
    
}
    

