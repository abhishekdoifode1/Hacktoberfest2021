#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fir(i, a, b) for(int i=a;i<b;i++)
#define rfir(i, a, b) for(int i=a;i>=b;i--)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define mod 1000000007
#define fast                  \
ios_base::sync_with_stdio(0); \
cin.tie(0);                   \
cout.tie(0);
#define tests                 \
int tt;                       \
cin>>tt; while(tt--)
using namespace std;
/****************************/


//General Keyword :- Subarray

/*
//Problem:- find the max sum subarray of size k, which's sum will be less than x
//Given:- an array, integer x and k
int main()
{
    //Sliding Window approach:-a window of k will keep sliding and we will over and over,
    //  add the next element as well as remove the last element in the window.
    //O(N)complexity
    ans = 0;
    int sum = 0;
    fir(i, 0, k){   
        sum+=arr[i];
    }
    if(sum<x)ans=sum;
    fir(i, k, n){   
        sum+= arr[i] - arr[i-k];
        if(sum<x)ans = max(ans, sum);
    }
    cout<<ans<<endl;
return 0;
}
*/





/*
//Problem:- For a given array and an integer x, find the minimum length of subarray
//          for which its (sum > x)
int main(){
    //Given Things
    int n; cin>>n;
    int arr[n];
    fir(i, 0, n)cin>>arr[i];
    int x; cin>>x;
    //for brute force approach, O(N^2) be the time complexity
    int ans=n+1;    
    fir(i, 0, n){
        int sum=0;
        fir(j, i, n){
            sum+=arr[j];
            if(sum>x)ans=min(j-i+1, ans);
        }
    }
    cout<<((ans!=n+1)?(ans):(-1))<<endl;
    //Sliding Window approach:- O(N)
    int sum = 0;
    ans = n+1;
    int start = 0;
    int end = 0;
    while (end < n){
        while(sum <= x && end < n){
            sum+=arr[end++];
        }
        while(sum > x && start < n){
            if(end - start < ans){
                ans = end - start;
            }
            sum -= arr[start++];
        }
    }
    cout<<((ans!=n+1)?(ans):(-1))<<endl;
    
    return 0;
}
*/




/*
//Problem:- Print the subarray in which, number is divisible by 3, formed from concatenating
//          the elements of the subarray of length k formed from a given array
//Given, an array and an integer k
int main(){
    // Brute force:- O(N^2)
    //ie, check for all the subarrays of length k and the divisibility by 3 of 
    //all numbers made from of the elements.
    //Sliding Window Approach:- O(N)
    int n; cin>>n;
    int arr[n];
    fir(i, 0, n)cin>>arr[i];
    int k; cin>>k;
    pair<int, int>ans = make_pair(-1, 0);
    int sum=0;
    fir(i, 0, k){
        sum+=arr[i];
    }
    
    bool found=false;
    if(sum%3==0){
        ans=make_pair(0, k-1);
        found = true;
    }
    fir(i, k, n){
        if(found)break;
        sum+=arr[i] - arr[i-k];
        if(sum%3==0){
            ans=make_pair(i-k+1, i);
            found = true;
        }
    }
    if(ans.first == -1){
        cout<<"No such subarray is present"<<endl;
    }
    else{
        fir(i, ans.first, ans.second+1){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/




/*
// Problem:- Find the largest substring which contains no repeating characters.
//Logic :- we save the index of last occurance of a char in the hash map.
int main(){
    string s = "prateekbhaiya";
    int max_window_len=0;
    int window_len = 0;
    int startWindow=-1;
    //we will save the last occurance of a char in this map.
    unordered_map<char, int>ma;
    int i=0, j=0;
    while(j<s.length()){
        char ch = s[j];
        if(ma.count(ch) and ma[ch]>=i){
            i = ma[ch]+1;
            window_len = j-i;
        }
        ma[ch]=j;
        window_len++;
        j++;
        if(window_len > max_window_len){
            max_window_len = window_len;
            startWindow = i;
        }
    }
    cout<<s.substr(startWindow, max_window_len)<<endl;
    return 0;
}
*/



/*
//Problem:- Given two strings, one big string and another small sting. find the smallest window in the big
//      string which contains all the characters of the small string.
string stringWindow(string s, string p){
    int FP[256]={0};
    int FS[256]={0};
    for(int i=0; i<p.length(); i++){
        FP[p[i]]++;
    }
    int cnt=0;
    int start=0;
    int window_size_min=INT_MAX;
    int minIdx=-1;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        FS[ch]++;
        if(FP[ch]!=0 && FS[ch] <= FP[ch]){
            cnt++;
        }
        int window_size;
        if(cnt==p.length()){
            while(FP[s[start]]==0 || FS[s[start]]>FP[s[start]]){
                FS[s[start]]--;
                start++;
            }
            window_size = i-start+1;
            if(window_size < window_size_min){
                window_size_min  = window_size;
                minIdx = start;
            }
        }
    }
    if(minIdx==-1){
        return "Nothing";
    }
    return s.substr(minIdx, window_size_min);
}
int main(){
    string s, p;
    // s = "hello";
    // p = "oel";
    cin>>s>>p;
    cout<<stringWindow(s, p)<<endl;
}
*/
