#include<bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int i=1;
    int j=0;
    int p=1;
    int r=1;
    while(i<n && j<n)
    {
        if(at[i]<=dt[j])
        {
            p++;
            i++;
        }
        else if(at[i]>dt[j])
        {
            p--;
            j++;
        }
        if(r<p)
        {
            r=p;
        }
    }
    return r;

}