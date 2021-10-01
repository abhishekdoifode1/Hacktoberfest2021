//https://practice.geeksforgeeks.org/viewSol.php?subId=ac050ffdd037b79f148e0c699ad454b9&pid=700384&user=vj89800
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends





class Solution {
private:
public:
	int minSwaps(vector<int>&arr){
	    // Code here
	    int n=arr.size();
	pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
 
    // Sort the array by array 
    // element values to
    // get right position of 
    // every element as second
    // element of pair.
    sort(arrPos, arrPos + n);
 
    // To keep track of visited elements. 
    // Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);
 
    // Initialize result
    int ans = 0;
 
    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;
 
        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
 
            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }
 
        // Update answer by adding current cycle. 
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }
 
    // Return result
    return ans;
	}
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
