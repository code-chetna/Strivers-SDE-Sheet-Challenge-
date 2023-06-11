#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int cnt=1;
	int ele=arr[0];
	for(int i=1;i<n;i++)
	{
		
        if(cnt == 0) {
          ele = arr[i];
	      cnt=1;
        }
		else if(arr[i]==ele)
		cnt++;
		else
		{
				  cnt--;
        }
	}
	int cnt1=0;
	for(int i=0;i<n;i++)
	{
		if(ele==arr[i])
		cnt1++;
	}
	if(cnt1>n/2)
	return ele;
	return -1;
}