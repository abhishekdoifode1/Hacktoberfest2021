#include <iostream>
using namespace std;
int main()
{
    short int t,i;
    int n,alice=0,bob=0;
    cin>>t;
    for(j=1;i<=t;i++)
    {
        cin>>n;
        long int a[n],b[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];
            if(a[i]>b[i])
            alice++;
            else if(a[i]<b[i])
            bob++;
        }
        if(alice<bob)
        cout<<"Alice"<<endl;
        else if(bob>alice)
        cout<<"Bob"<<endl;
        else if(alice=bob)
        cout<<"Tie"<<endl;

    }

}