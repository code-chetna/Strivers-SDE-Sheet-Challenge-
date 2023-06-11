#include <bits/stdc++.h>
void swappy(vector<int>&arr1,vector<int>&arr2,int ind1,int ind2)
{
if(arr1[ind1]>arr2[ind2])
{
	swap(arr1[ind1],arr2[ind2]);
}
}
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int len=m+n;
	int gap=(len/2)+(len%2);
	while(gap>0)
	{
		int l=0;
		int r=l+gap;
		while(r<len)
		{
		  if(l<m && r>=m)
		  {
			  swappy(arr1,arr2,l,r-m);
		  }
		  else if(l>=m)
		  {
			  swappy(arr2,arr2,l-m,r-m);
		  }
		  else
		  {
			  swappy(arr1,arr1,l,r);
		  }
          l++;
		  r++;
		}
		if(gap==1)
		break;
		gap=(gap/2)+(gap%2);
	}
	for(int i=m;i<(m+n);i++)
	{
		arr1[i]=arr2[i-m];
	}
	return arr1;
}