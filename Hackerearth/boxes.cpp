#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int a=0;a<T;a++)
    {
    int N,i,j;
    long int sum=0;
    cin>>N;
    long int num[N];
    for(i=0;i<N;i++)
    {
        cin>>num[i];
        for(j=0;j<i;j++)
        {
            if(num[i]>num[j])
            sum+=num[j];
        }
    }
    cout<<sum<<endl;
    }
    return 0;
}