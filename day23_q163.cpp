#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&vis,int **arr,int i,int j,int n,int m)
{
vis[i][j]=1;
queue<pair<int,int>>q;
q.push({i,j});
while(!q.empty())
{
   int row=q.front().first;
   int col=q.front().second;
   q.pop();
   for(int delrow=-1;delrow<=1;delrow++)
   {
      for(int delcol=-1;delcol<=1;delcol++)
      {
         int nextrow=delrow+row;
         int nextcol=delcol+col;
         if(nextrow>=0 && nextrow<n && nextcol>=0 && nextrow<m && arr[nextrow][nextcol]==1 && vis[nextrow][nextcol]!=1)
         {
            vis[nextrow][nextcol]=1;
            q.push({nextrow,nextcol});
         }
      }
   }
}

}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
  vector<vector<int>>vis(n,vector<int>(m,0));
  int count=0;
  for(int i=0;i<n;i++)
  {
     for(int j=0;j<m;j++)
     {
        if(!vis[i][j] && arr[i][j]==1)
        {
           bfs(vis,arr,i,j,n,m);
           count++;
        }

     }
  }

return count;

}
