#include <iostream>

using namespace std;

int fib(int n) {
	if (n == 0) {
		return 0;
	} else if (n < 3) {
		return 1;
	} else {
		return fib(n-1) + fib(n-2);
	}
}

int main(void) {
	int upTo = 10, ctr = 0;
	while (ctr < upTo) {
		cout << fib(ctr) << " ";
		++ctr;
	}
}
