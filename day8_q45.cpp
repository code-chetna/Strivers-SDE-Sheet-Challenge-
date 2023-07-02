#include <bits/stdc++.h> 
bool cmp(vector<int>&jobs1,vector<int>&jobs2)
{
 return jobs1[1]>jobs2[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here//deadline //profit
    sort(jobs.begin(),jobs.end(),cmp);
    int n=jobs.size();
    int maxidead=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxidead=max(maxidead,jobs[i][0]);
    }
    vector<int>schedule(maxidead+1,-1);
    int maxiprofit=0;
    for(int i=0;i<n;i++)
    {
        int currentprofit=jobs[i][1];
        int currentdead=jobs[i][0];
        for(int j=currentdead;j>0;j--)
        {
            if(schedule[j]==-1)
            {
                schedule[j]=1;
                maxiprofit+=currentprofit;
                break;
            }

        }


    }
return maxiprofit;

}