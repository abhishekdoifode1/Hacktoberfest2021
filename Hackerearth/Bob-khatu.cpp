#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int L=0,D=0,R=0,U=0,i;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='L')
        L++;
        else if(s[i]=='R')
        R++;
        else if(s[i]=='D' )
        D++;
        else if(s[i]=='U' )
        U++;
    }
    cout<<(R-L)<<" "<<(U-D);
    return 0;
}