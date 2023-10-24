/*
    Problem Link:
    https://leetcode.com/problems/daily-temperatures/
*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack <pair<int,int>> s;
        vector <int> ans;
        for(int i=t.size()-1; i>=0; i--){
            while(s.size()>0 && s.top().first<=t[i]){
                s.pop();
            }
            if(s.size()==0) ans.push_back(0);
            else ans.push_back(s.top().second-i);
            s.push({t[i],i});        
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};