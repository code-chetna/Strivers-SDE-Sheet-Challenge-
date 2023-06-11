#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	long long xi=x;
	long long ans=1;
	while(n>0)
	{
		if(n%2==0)
		{
			xi=(xi*xi)%m;
			n/=2;
		}
		else
		{
			ans=(xi*ans)%m;
			n=n-1;
		}
	}
	return (ans%m);

}