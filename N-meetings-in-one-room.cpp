 int maxMeetings(int start[], int end[], int n)
   {
       // Your code here
       vector<pair<int,int>>v;
       for(int i=0;i<n;i++){
           v.push_back({end[i],start[i]});
       }
       sort(v.begin(),v.end());
       
       int count = 1;
       pair<int,int>p = v[0];
       for(int i=1;i<n;i++){
           if(v[i].second>p.first){
               count++;
               p = v[i];
           }
       }
       return count;
   }
