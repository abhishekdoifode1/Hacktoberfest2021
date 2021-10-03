#include <bits/stdc++.h>
using namespace std;

int main()
{
    int binarynum[32];
    int n;
    int i=0;
    cin>>n;
    while(n>0)
    {
        binarynum[i]=n%2;
        cout<<binarynum[i];
        n=n/2;
        i++;
    }
}