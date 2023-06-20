#include <bits/stdc++.h> 
void merge(int l,int mid,int r,vector<int>&arr)
{
int i=l;
int j=mid+1;
vector<int>temp;
while(i<=mid && j<=r)
{
  if (arr[i] <=arr[j]) {
    temp.push_back(arr[i]);
    i++;
	
  }
  else
  {
	  	temp.push_back(arr[j]);
		j++;
		
  }
        
}
while(i<=mid)
{
temp.push_back(arr[i]);
i++;

}
while(j<=r)
{
temp.push_back(arr[j]);
j++;

}
for(int i=l;i<=r;i++)
{
	arr[i]=temp[i-l];
}

}
int count(int l,int mid,int r,vector<int>&arr)
{
	int cnt=0;
	int ptr=mid+1;
	for(int i=l;i<=mid;i++)
	{
		while(ptr<=r && arr[i]>2*arr[ptr])
		{
			ptr++;
		}
		cnt+=(ptr-(mid+1));
	}
	//cout<<"count is"<<cnt;
	return cnt;
}
int mergesort(int l,int r,vector<int>&arr)
{
	int cnt=0;
        if (l<r) {
			int mid=l+(r-l)/2;
          cnt+=mergesort(l,mid,arr);
          cnt+=mergesort(mid+1,r,arr);
          cnt+=count(l,mid,r,arr);
          merge(l,mid,r,arr);
        }
return cnt;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	
	return mergesort(0,n-1,arr);
}