bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n=mat.size();
    int m=mat[0].size();
    int s=0;
    int e=(m*n)-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(mat[mid/m][mid%m]>target)
            {
                e=mid-1;
            }
            else if(mat[mid/m][mid%m]<target)
            {
                s=mid+1;
            }
            else
            return 1;
        }
        return 0;
}