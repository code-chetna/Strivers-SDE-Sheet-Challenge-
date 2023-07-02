int longestSubSeg(vector<int> &arr , int n, int k){
    int zerocount=0;
    int i=0;
    int ans=0;
    for(int j=0;j<n;j++)
    {
        
        if(arr[j]==0)
        zerocount++;
        
        while(zerocount>k)
        {
            if(arr[i]==0)
            zerocount--;
            i++;
        }
        ans=max(ans,j-i+1);
        
    }
    return ans;
    // Write your code here.
}
