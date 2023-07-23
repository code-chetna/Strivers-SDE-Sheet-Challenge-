#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>>adj(v);
    for(int i=0;i<e;i++)
    {

        adj[edges[i][0]].push_back(edges[i][1]);
    }
    int indegree[v]={0};
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i])
        indegree[it]++;
    }
    vector<int>topo;
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
while(!q.empty())
{
int node=q.front();
q.pop();
topo.push_back(node);
for(auto it:adj[node])
{
    indegree[it]--;
    if(indegree[it]==0)
    {
        q.push(it);
    }
}
}
   
return topo;

}