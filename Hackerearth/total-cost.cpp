#include <bits/stdc++.h>
using namespace std;
int main()
{
    int P,H,sum=0;
    short int S,T,x,i;
    cin>>P>>S>>T>>H>>x;
    for(i=1;i<=x;i++)
    {
        
        if(S>T)
        {
            sum+=P;
        }
        else if(S<=T)
        {
            sum+=H;

        }
        S=S-1;
    }
    cout<<sum;
}