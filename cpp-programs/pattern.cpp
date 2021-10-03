// C++ code to demonstrate star pattern
#include <iostream>
using namespace std;

void pypart(int n)
{
	for (int i = n; i > 0; i--) {

		for (int j = 0; j < i; j++) {

			cout << "* ";
		}

		cout << endl;
	}
}

int main()
{
	int n = 5;
	pypart(n);
	return 0;
}