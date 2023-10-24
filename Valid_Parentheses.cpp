#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    stack <char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                if(st.size()==0) return false;
                else if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || s[i]==']' && st.top()=='[') st.pop();
                else return false;
            }
        }
        if(st.size()==0) return true;
        else return false;
}