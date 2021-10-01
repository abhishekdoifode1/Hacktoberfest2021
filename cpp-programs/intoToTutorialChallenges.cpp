// https://www.hackerrank.com/challenges/tutorial-intro/submissions/code/172225424

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int V,n,a[1000],i;
    cin>>V;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==V)
        {
            cout<<i;
            break;
        }
    }
}
