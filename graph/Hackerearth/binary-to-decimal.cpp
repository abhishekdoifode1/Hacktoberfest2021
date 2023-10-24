#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int st=stoi(s);
    int str;
    str=0;
    for(int i=0;i<=s.length();i++)
    {
        int a=pow(10,i);
      str+= (st% (pow(10,i)))*pow(2,i);
    }
    cout<<str;

    return 0;
}