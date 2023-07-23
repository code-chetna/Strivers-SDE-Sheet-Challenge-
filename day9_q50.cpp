#include <bits/stdc++.h> 
 void solve(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, int size){
        ans.push_back(ds);
        for(int i=idx;i<size;i++)
        {
            if(i!=idx && nums[i]==nums[i-1])
            continue;
            ds.push_back(nums[i]);
            solve(i+1,nums,ds,ans,size);
            ds.pop_back();
        }
    }
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
     sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,arr,ds,ans,n);
        return ans;

}