class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end());
        for(auto i : intervals){
            if(v.empty()==1 || v.back()[1]<i[0]){
                v.push_back(i);
            }
            else{
                v.back()[1]=max(v.back()[1], i[1]);
            }
        }
        return v;
    }
};