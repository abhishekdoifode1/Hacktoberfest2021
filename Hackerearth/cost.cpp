#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> st;
//    for(int i=0;i<4;i++)
   vector<char> strg;
     string s;
     for(int j=0;j<2;j++)
     {
     cin>>s;
     for(int i=0;i<s.length();i++)
     strg.push_back(s[i]);
     st.push_back(strg);
     }
     cout<<st.size();

}