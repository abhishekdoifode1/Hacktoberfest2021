#include<bits/stdc++.h>
using namespace std;
int main()
{
    short int n;
    cin>>n;
    for(;;)
    {
        n=n+1;
        short int c=n,i,d;
        if(n%3!=0)
        {   
             d=0;
            for(i=0;i<=log10(n);i++)
            {
                int a=c%10;
                c=c/10;
                if(a==3)
                break;
               else
               d++;
               
            }
        
        }
        
            if(d==(int(log10(n))+1))
            break;
        
    }
    cout<<n;
    return 0;
}