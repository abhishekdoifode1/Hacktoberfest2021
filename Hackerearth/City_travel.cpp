#include <iostream>
using namespace std;
int main()
{
    long int s,x,i;
    short int n,j;
    cin>>s>>x>>n;
    long int t[n],y[n],limit;
    for(i=0;i<n;i++)
        {
            cin>>t[i]>>y[i];
        }
    
    i=1;
    while(1)
    {
        for(j=0;j<n;j++)
        {
            if(t[j]==i)
            {
                limit=y[j];
             break;
            }
            else
            {
                limit=x;
            }
        }
        // at day=i,i can travel limit ;
        s=s-limit;
        if(s<=0)
        break;
        i++;
    }
    cout<<i;
    return 0;
}
