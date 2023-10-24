#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1;
    string s2,s;
    cin>>s1>>s2;
    s1.erase(s1.begin()+2,s1.end());
    s2.erase(0,4);
    s1.append(s2);
    cout<<s1;
}
