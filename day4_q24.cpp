#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    unordered_map<char,int>mp;
    int n=input.length();
    int right=0;
    int left=0;
    int len=0;
    while(right<n)
    {
        if(mp.find(input[right])!=mp.end())
        {
            left=max(left,1+mp[input[right]]);
        }
        mp[input[right]]=right;
        len=max(len,right-left+1);
        right++;
    }
    return len;
}