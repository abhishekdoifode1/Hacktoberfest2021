// C++ program to find sum of two large numbers. 
#include<bits/stdc++.h> 
using namespace std; 

// Function for finding sum of larger numbers 
string findSum(string str1, string str2) 
{ 
	// Before proceeding further, make sure length 
	// of str2 is larger. 
	if (str1.length() > str2.length()) 
		swap(str1, str2); 

	// Take an empty string for storing result 
	string str = ""; 

	// Calculate length of both string 
	int n1 = str1.length(), n2 = str2.length(); 

	// Reverse both of strings 
	reverse(str1.begin(), str1.end()); 
	reverse(str2.begin(), str2.end()); 

	int carry = 0; 
	for (int i=0; i<n1; i++) 
	{ 
		// Do school mathematics, compute sum of 
		// current digits and carry 
		int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
		str.push_back(sum%10 + '0'); 

		// Calculate carry for next step 
		carry = sum/10; 
	} 

	// Add remaining digits of larger number 
	for (int i=n1; i<n2; i++) 
	{ 
		int sum = ((str2[i]-'0')+carry); 
		str.push_back(sum%10 + '0'); 
		carry = sum/10; 
	} 

	// Add remaining carry 
	if (carry) 
		str.push_back(carry+'0'); 

	// reverse resultant string 
	reverse(str.begin(), str.end()); 

	return str; 
} 

// Driver code 
int main() 
{ 
	string str1 = "12"; 
	string str2 = "198111"; 
	cout << findSum(str1, str2); 
	return 0; 
} 
