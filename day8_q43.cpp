#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int,pair<int, int>>> ans;
    for(int i = 0; i < start.size(); i++)
        ans.push_back({end[i],{i+1,start[i]}});
    
    sort(ans.begin(),ans.end()); 
    int n = ans.size();
    // int e = -1;
    vector<int> res;
    res.push_back(ans[0].second.first);
    for(int i = 1; i < n; i++){
            if(ans[i].second.second > end[res.back()-1]){
            res.push_back(ans[i].second.first);
            // e = val.first + 1;
        }
    }
    return res;
}
