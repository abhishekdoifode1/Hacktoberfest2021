#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,i;
    short int x,y,l,m,a,b;
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>x>>y>>l>>m>>a>>b;
        if(b>=m)
        {
            if(a+l<=x)
            cout<<"bottom-right"<<endl;
            else
            cout<<"bottom-left"<<endl;
            

        }
        else if(b<m)
        {
            if(a+l<=x)
            cout<<"top-right"<<endl;
            else
            cout<<"top-left"<<endl;
        }
    }
    return 0;
}