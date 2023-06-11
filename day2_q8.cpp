vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    int n=intervals.size();
    vector<vector<int>>ans;
    if(n==1)
        {
            ans.push_back({intervals[0][0],intervals[0][1]});
            return ans;
        }
    sort(intervals.begin(),intervals.end());
    int i=0;
    while(i<n)
    {
        int start=intervals[i][0];
        int end=intervals[i][1];
        
        if(!ans.empty() && ans.back()[1]>end)
        {
            i++;
            continue;
        }
       if(ans.empty() || start>ans.back()[1]){
           if(i==n-1)
           {
               ans.push_back({start,end});
               break;
           }
           if(intervals[i+1][0]<end){
           end=max(end,intervals[i+1][1]);
           ans.push_back({start, end});
           i++;
           }
           else{
               ans.push_back({start,end});
           }
       }
       else if(!ans.empty() && ans.back()[1]<end)
       {
           ans.back()[1]=end;
       }
       i++;
    }
    return ans;
    
}
