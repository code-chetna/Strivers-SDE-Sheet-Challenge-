//pascal triangle
#include <bits/stdc++.h>
vector<long long int>getrow(int row)
{
  vector<long long int>a1;
  a1.push_back(1);
  long long res=1;
  for(int i=1;i<row;i++)
  {
    res*=(row-i);
    res/=i;
    a1.push_back(res);
  }
  return a1;
}
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>>ans;
  for(int i=1;i<=n;i++)
  {
    ans.push_back(getrow(i));
  }
  return ans;
}
