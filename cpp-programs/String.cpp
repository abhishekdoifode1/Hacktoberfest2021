#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    string str; 
  
    // Get the string 
    getline(cin, str); 
  
    // Print the words 
    istringstream ss(str); 
    do { 
        string word; 
        ss >> word; 
        cout << word << endl; 
    } while (ss); 
} 
