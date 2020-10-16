#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int x1[7],x2,v1,v2;
    // cin>>x1;
    
int arr[] = { 1, 45, 54, 71, 76, 12 }; 
  
    // Compute the sizes 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Print the array 
    cout << "Array: "; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
  
    // Find the maximum element 
    cout << "\nMax Element = "
         << *max_element(arr, arr + n); 
    return 0; 

}