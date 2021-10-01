#include<bits/stdc++.h> 
using namespace std; 
 
void merge(int arr[], int l, int m, int r) 
{ 
    int n1 = m - l + 1; 
    int n2 = r - m;   
    int L[n1], R[n2];  
    for(int i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for(int j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
    int i = 0;
    int j = 0;  
    int k = l; 
      
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j])  
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else 
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1)  
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    }  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l + (r - l) / 2;  
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
 
int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Given array is \n"; 
    for(int i=0;i<arr_size;i++)
    {
    	cout<<arr[i]<<" ";
	}
  
    mergeSort(arr, 0, arr_size - 1); 
  
    cout << "\nSorted array is \n"; 
    
    for(int i=0;i<arr_size;i++)
    {
    	cout<<arr[i]<<" ";
	}
    return 0; 
} 
