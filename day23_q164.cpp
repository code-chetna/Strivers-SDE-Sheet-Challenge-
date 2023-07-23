#include<bits/stdc++.h>
bool check(vector<int>&color,vector<vector<int>>&adj,int start)
{
	queue<int>q;
	q.push(start);
	color[start]=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto it:adj[node])
	    {
                  if (color[it] == -1) {
                    color[it] = !color[node];
					q.push(it);
                  }

                  else if (color[it] == color[node])
                    return false;
			
	    }
	}	
	return true;
	

}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n=edges[0].size();
	vector<vector<int>>adj(n);
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(edges[j][i]==1)
			{
				adj[j].push_back(i);
			}
		}
		
	}
	//cout<<"outside for"<<endl;
	vector<int>color(n,-1);
	for(int i=0;i<n;i++)
	{
		if(color[i]==-1)
		{
			if(!check(color,adj,i))
			return false;
		}
		
	}
	
	return true;
}