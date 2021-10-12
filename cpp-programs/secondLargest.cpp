#include <iostream>

using namespace std;

int secondLargest(int arr[], int n) {
    int max=0, res=-1;
    for(int i=1;i<n;i++) {
        if(arr[i] > arr[max]) {
            res = max;
            max = i;
        } else if (arr[i]>arr[res] && arr[i]!=arr[max]) {
            res = i;
        }
    }
    return arr[res];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    
    cout << secondLargest(arr, n) << endl;

    return 0;
}
