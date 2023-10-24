#include <iostream>
using namespace std;
int main()
{
    int t,i;
    long int l,r,s;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>l>>r>>s;
        int j=1;
        while(1)
        {
            int a,b;
            if(s*j>=l && s*(j-1)<l)
            cout<<j<<" ";
            else if(s*j<=r && s*(j+1)>r)
            {
                cout<<j;
                break;
            }
            j++;
        }
        cout<<endl;
    }
}