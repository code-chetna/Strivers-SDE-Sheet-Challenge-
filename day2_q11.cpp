 #include <bits/stdc++.h>
 pair<int, int> missingAndRepeating(vector<int>& arr, int n) {
   //Write your code here 
    long long sn=0;
    long long sn2=0;
	for(int i=0;i<arr.size();i++)
	{
		sn+=arr[i];
		sn2+=(long long)arr[i]*(long long)arr[i];
	}
	long long sum_n=(n*(n+1))/2;
	long long sum_n2=(n)*(n+1)*(2*n+1)/6;
	long long val1=sn-sum_n;
	long long  val2=sn2-sum_n2;
	val2=val2/val1;
        long long x=(val1+val2)/2;
        long long y=val2-x;
        return {(int)y,(int)x};
 }

 //another method
  #include <bits/stdc++.h>
 pair<int, int> missingAndRepeating(vector<int>& arr, int n) {
int xored=0;
for(int i=0;i<n;i++)
{
	xored=xored^arr[i];
	xored=xored^(i+1);
}
int bitpos=0;
while(1)
{
	if((xored & (1<<bitpos))!=0)
	break;
	bitpos++;
}
int zero=0;
int one=0;
for (int i = 0; i < n; i++) {
  if ((arr[i] & (1 << bitpos) )!= 0) {
    one = one ^arr[i];
	
  } 
  else
  {
	   zero ^= arr[i];
  }
  if(((i+1) & (1 << bitpos)) != 0)
	{
		one^=(i+1);
  } else {
    zero ^= (i + 1);
  }
}
int cnt=0;
for(int i=0;i<n;i++)
{
	if(arr[i]==zero)
	cnt++;
}
if(cnt==2)
{
return {one,zero};
}
return {zero,one};
}

