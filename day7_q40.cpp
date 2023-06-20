#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
   
    long l=0;
    long r=n-1;
    long leftmax=arr[l];
    long rightmax=arr[r];
    long res=0;
    while(l<=r)
    {
        if(arr[l]<=arr[r])
        {
            if(leftmax<=arr[l])
            leftmax=arr[l];
            else
            res+=(leftmax-arr[l]);


            l++;

        }
        else
        {
            if(arr[r]>=rightmax)
            rightmax=arr[r];
            else
            res+=(rightmax-arr[r]);

            
            r--;
        }

    }
    return res;
}