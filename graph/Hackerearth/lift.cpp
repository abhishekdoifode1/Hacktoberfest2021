#include <iostream>
using namespace std;

void liftcall(int a);
int main()
{
cout<<"enter test cases";

int t,i;
cin>>t;
int a[t];

if(t>0 && t<=100000)
{
for(i=0;i<t;i++)
{
cin>>a[i];
}
for(i=0;i<t;i++)
if(a[i]<8)
liftcall(a[i]);

}
return 0;

}

void liftcall(int a){
static int A=0,B=7;
int x=(A+B)/2;
if(a>x)
{
    B=a;
    cout<<"B"<<endl;
}
else
{
    A=a;
    cout<<"A"<<endl;
}
}