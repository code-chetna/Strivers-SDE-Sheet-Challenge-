#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    int profit=0;
    int mini=prices[0];
    for(int i=0;i<n;i++)
    {
        int cost=prices[i]-mini;
        profit=max(cost,profit);
        if(prices[i]<mini)
        {
            mini=prices[i];
        }
    }
    return profit;
}