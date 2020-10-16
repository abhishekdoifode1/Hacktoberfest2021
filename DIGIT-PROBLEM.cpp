#include <bits/stdc++.h>
// #include <math.h>
using namespace std;

int main()
{
    short int k;
    long long int x;
    int digits,i,a;
    cin>>x>>k;
    for(i=1;i<=k;i++)
    {
        digits=log10(x)+1;
        a=x/long(pow(10,(digits-i)));
    cout<<a<<endl;
    }

}