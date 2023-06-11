int merge(vector<int>a,int low,int mid,int high)
{
int start=low;
int end=mid+1;
int count=0;
vector<int >temp;
int  i=0;
int  j=0;
while(start<=mid && end<=high)
{
    if(a[start]<=a[end])
    {
        temp.push_back(a[start]);
    
        start++;
    }
    else
    {
        temp.push_back(a[end]);
        
        end++;
        count+=(mid-start+1);
    }
    
}
while(start<=mid)
{
temp.push_back(a[start]);
start++;

}
while(end<=high)
{
temp.push_back(a[end]);
end++;

}
for(int i=low;i<=high;i++)
{
    a[i]=temp[i-low];
}
return count;

}
int mergesort(vector<int>a,int low,int high)
{
    int count=0;
    
  if (low < high) {
    int mid = (high + low) / 2;
    count+=mergesort(a, low, mid);
    count+=mergesort(a, mid + 1, high);
    count+=merge(a, low, mid, high);
    return count;
  }
  else
  return count;
}

int numberOfInversions(vector<int>&a, int n) {
    
    // Write your code here.
    return mergesort(a,0,n-1);

}