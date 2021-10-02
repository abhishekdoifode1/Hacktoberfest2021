#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

unordered_map <string, bool> mp;

bool Solve(string a, string b){
	if(a.compare(b) == 0)
		return true;

	if(a.size() <= 1)
		return false;

	string key = a;
	key.push_back(' ');
	key.append(b);

	if(mp.find(key) != mp.end())
		return mp[key];

	int n = a.size();
	bool flag = false;

	for(int i=1; i<=n-1; i++){
		int condition1 = Solve(a.substr(0, i), b.substr(n-i, i)) && Solve(a.substr(i, n-i), b.substr(0, n-i));
		int condition2 = Solve(a.substr(0, i), b.substr(0, i)) && Solve(a.substr(i, n-i), b.substr(i, n-i));

		if(condition1 || condition2){
			flag = true;
			break;
		}
	}
	return mp[key] = flag;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	string a = "great";
	string b = "eatgr";

	a = "great";
	b = "great";

	a = "coder";
	b = "ocred";

	if(a.size() != b.size())
		cout<<0<<endl;
	if(a.size() == 0 && b.size() == 0)
		cout<<1<<endl;

	cout<<Solve(a, b);
}