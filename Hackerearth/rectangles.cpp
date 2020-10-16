#include <bits/stdc++.h>
using namespace std;
int counts(int a);
int main()
{
    short int T,S,i;
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>S;
        int counter=0;
        for(int j=1;j<=S;j++)
        {
            counter+=counts(j);
        }
        cout<<counter;
    }
    return 0;
}

int counts(int a)
{
    int i;
    int count=0;
    for(i=1;i*i<=a;i++)
    {
        if(a%i==0)
        count++;
    }
    return count;
}