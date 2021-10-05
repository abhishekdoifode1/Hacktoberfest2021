SIMPLE AND CLEAN SOLUTION 
//GREEDY APPROACH

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>> jobs;

        int index=-1;
        for(int i=0;i<n;i++)
        {
            jobs.push_back({arr[i].profit, arr[i].dead});
            index=max(index,arr[i].dead);
        }
        
     sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());
        
        
        vector<int> fill(index,-1);
        int totalprofit=0;
        int job=0;
        
        for(int i=0;i<n;i++)
        {
            int j=jobs[i].second-1;
            
            while(j>=0 && fill[j]!=-1)
            {
                j--;
            }
            
            if(j>=0 && fill[j]==-1)
            {
                fill[j]=i;
                totalprofit+=jobs[i].first;
                job++;
            }
        }
        
        vector<int> ans(2);
        ans[0]=job;
        ans[1]=totalprofit;
        
        return ans;
        
    } 
