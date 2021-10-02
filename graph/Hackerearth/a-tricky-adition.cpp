#include <bits/stdc++.h>
using namespace std;
string string_conversion(long long int a);
int int_conversion(string s);
string reverse_string(string s);
int main()
{
 long long int n,m;
 cin>>n>>m;
string s1=string_conversion(n);
string s2=string_conversion(m);
s1=reverse_string(s1);
s2=reverse_string(s2);
n=int_conversion(s1);
m=int_conversion(s2);
long long int sum;
sum=n+m;
string s3=string_conversion(sum);
s3=reverse_string(s3);
sum=int_conversion(s3);
cout<<sum;
return 0;

}

string string_conversion(long long int a)
{
    stringstream ss;
    ss<<a;
    string s;
    ss>>s;
    return s;
}

int int_conversion(string s)
{
    stringstream ss;
    ss<<s;
    int a;
    ss>>a;
    return a;
}

string reverse_string(string s)
{
    
    for(int i=0;i<(s.length())/2;i++)
    {
        swap(s[i],s[s.length()-i-1]);
    }
    return s;
}