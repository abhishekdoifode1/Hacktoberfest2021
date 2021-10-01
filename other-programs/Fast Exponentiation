//C++ code for fast exponentiation using bitmasking
//helpfull in competitive programming
#include<bits/stdc++.h>
using namespace std;
long long cal_a_to_the_power_b(long long a,long long b)
{
    if(b==0)
        return 1;
    long long res=1;
    while(b>0)
    {
        if((b&1)==1)
        {
            res=res*a;  
        }
        b=b>>1;
        a=a*a;
    }
    return res;
}
int main()
{
    long long a,b;
    cout<<"input the value of base"<<"\n";
    cin>>a;
    cout<<"input the value of power"<<"\n";
    cin>>b;
    cout<<"a to the power b is"<<"\n";
    cout<<cal_a_to_the_power_b(a,b)<<"\n";
    return 0;
}
