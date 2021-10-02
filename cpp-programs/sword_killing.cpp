#include <bits/stdc++.h>
using namespace std;

int main()
{

	int person = 100;

	vector<int> a(person);


	for (int i = 0; i < person; i++) {
		a[i] = i + 1;
	}

	int pos = 0;

	while (a.size() > 1) {
	
		pos++;
		
		pos %= a.size();
		
		a.erase(a.begin() + pos);
		
	}


	cout << a[0];

	return 0;
}
