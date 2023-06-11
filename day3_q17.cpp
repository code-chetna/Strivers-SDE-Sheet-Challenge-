#include <bits/stdc++.h> 
int ans(vector<vector<int>>&dp,int m,int n,int i,int j)
{
if(i==n-1 && j==m-1)
return 1;
if(i<0 || i>=n || j<0||j>=m)
return 0;
if(dp[i][j]!=-1)
return dp[i][j];
return dp[i][j]=ans(dp,m,n,i,j+1)+ans(dp,m,n,i+1,j);
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(n,vector<int>(m,-1));
	return ans(dp,m,n,0,0);

}