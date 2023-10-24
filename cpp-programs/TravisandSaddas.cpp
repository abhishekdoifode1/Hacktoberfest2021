/*
Explanation:
You are given a lucky number n. Lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Input
The first and only line of input contains a lucky number n (1 ≤ n ≤ 109).

Output
Print the index of n among all lucky numbers.

Examples
input
4
output
1
input
7
output
2
input
77
output
6
*/
#include <iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int main() {
    char a[20];//74747
    cin>>a;
    int len=strlen(a);
    int ans=(1<<len)-2;
    for(int i=len-1,pos=0;i>=0;pos++,i--){
    if(a[i]=='7'){ans+=(1<<pos);}}
    cout<<ans+1<<endl;
}
