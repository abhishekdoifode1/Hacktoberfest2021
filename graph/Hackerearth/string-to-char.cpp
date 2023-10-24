#include <iostream>
using namespace std;
int reverse(string s1,string s2,int a,int b);
int compare(string s1,string s2);

int main()
{
  string s;
  cin>>s;
  string str,stri=s;
  int a,b,i,count=0;
  cin>>a>>b;
  for(i=a;i<=(a+b)/2;i++)
    {
        str=s.replace(i,1,s,a+b-i,1);
        cout<<str<<endl;
    }
    for(i=(a+b+2)/2;i<=b;i++)
    {
        stri.replace(i,1,stri,a+b-i,1);
        cout<<stri<<endl;
    }
    reverse(str,stri,a,b);
    compare(str,stri)
    return 0;
}

int reverse(string s1,string s2,int a,int b)
{
    s1.erase(s1.begin()+(a+b+2)/2,s1.end());
    s2.erase(0,(a+b+2)/2);
    s1.append(s2);
    cout<<s1;
}
int compare(string s1,string s2)
{
    int count=0;
    for(int i=0;i<s1.length();i++)
    {
    if(s1.compare(i,1,s2,i,1))
    {
    count++;
    }
    }
    cout<<count;
    return 0;
}
