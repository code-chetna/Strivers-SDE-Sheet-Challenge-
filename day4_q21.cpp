#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int>s;
    int len=1;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    for(auto it:s)
    {
        int x=it;
        if(s.find(it-1)==s.end())
        {
            int cnt=1;
            while(s.find(x+1)!=s.end())
            {
                x=x+1;
                cnt++;
            }
            len=max(len,cnt);
        }
    }
    return len;
}