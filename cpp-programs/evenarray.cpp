#include <iostream>
#include <vector>
using namespace std;
int t,s,e,i;
vector<int>v;
int main()
{   cin>>t;
    while(t--)
    {   
        int a=0;
        int b=0;
        cin>>s;
        for(i=0;i<s;i++)
        {
            cin>>e;
            //v.at(i)=e;
            if((e%2)==0&(i%2)!=0)
            {a+=1;}
           
            if((e%2)!=0&(i%2)==0)
            {b+=1;}
        }
        if(a==b)
        {cout<<a<<"\n";}
        else
        {cout<<-1<<"\n";}
    }
}
