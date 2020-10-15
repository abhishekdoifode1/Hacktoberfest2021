#include <bits/stdc++.h>
using namespace std;

int reverse_num(int a);
int main()
{
    short int i,T;
    int n1,n2;
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>n1>>n2;
        int sum;
        sum=reverse_num(n1)+reverse_num(n2);
        sum=reverse_num(sum);
        cout<<sum;
    }
    return 0;
}

int reverse_num(int a)
{
    int count=0;
    for(int i=int(log10(a));i>=0;i--)
    {
       
        count+= (int(a%10)*pow(int(10),int(i)));
        cout<<count<<endl;
        a=a/10;
    }
    return count;

}