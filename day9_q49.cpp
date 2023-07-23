#include<bits/stdc++.h>
void getsum(int index,int sum,vector<int>&num,vector<int>&subsetsum,int n)
{
if(index==n)
{
subsetsum.push_back(sum);
return;
}
getsum(index+1,sum+num[index],num,subsetsum,n);
getsum(index+1,sum,num,subsetsum,n);
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	int n=num.size();	
	vector<int>subsetsum;
	getsum(0,0,num,subsetsum,n);
    sort(subsetsum.begin(),subsetsum.end());
	return subsetsum;

	
}