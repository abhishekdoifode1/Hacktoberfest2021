#include <iostream>

using namespace std;

int a[20][20], b[20][20], c[20][20];	// Matrices
int m, n, o, p;	// Dimensions
int i, j, k;	// Loop Control Variables

void mult() {
	for ( i=0; i<m; i++ ) 
		for ( j=0; j<p; j++ ) 
			for ( k=0; k<n; k++ ) 
				c[i][j] += a[i][k] * b[k][j];
}

int main() {
	for ( i=0; i<20; i++ )		// Initialise the Matrices
		for ( j=0; j<20; j++ )
			a[i][j] = b[i][j] = c[i][j] = 0;

	cout << "Enter dimensions of 1st Matrix: ";
	cin >> m
	    >> n;
	cout << "Enter dimensions of 2nd Matrix: ";
	cin >> o
	    >> p;
	
	if ( n != o )
		cout << "These matrices can't be muliplied!";

	else {

		cout << "Enter Elements of Matrix 1:\n";
		for ( i=0; i<m; i++ )
			for ( j=0; j<n; j++ )
				cin >> a[i][j];

		cout << "Enter Elements of Matrix 2:\n";
		for ( i=0; i<o; i++ )
			for ( j=0; j<p; j++ )
				cin >> b[i][j];
				
		mult();
		cout << "Multiplied Matrices:\n";
		for ( i=0; i<m; i++ ) {
			for ( j=0; j<p; j++ )
				cout << c[i][j] << "  ";
			cout << endl;
		}
	}

	return 0;
}
