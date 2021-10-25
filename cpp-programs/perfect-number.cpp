#include <iostream>
using namespace std;
int fact1(int res);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,n1,i,res,fact=1,sum=0,tmp;
        cin>>n;
        n1=n;
        while(n!=0)
        {
            res=n%10;
            tmp=fact1(res);
            sum+=tmp;
            n/=10;
        }
        if(n1==sum)
        cout<<"Perfect\n";
        else
        cout<<"Not Perfect\n";

    }
    return 0;
}
int fact1(int res)
{
    int i,fact=1;
    for(i=1;i<=res;i++)
            {
                fact=fact*i;
                
            }
            return fact;
}
