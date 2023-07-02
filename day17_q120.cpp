#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    //Write your code here.
    int ans=0;
    if(!root)
    return 0;
    queue < pair<TreeNode<int> *, int >>q;
    q.push({root, 0});
    while(!q.empty())
    {
        int size=q.size();
        int first,last;
        int mini=q.front().second;
        for(int i=0;i<size;i++)
        {
            TreeNode<int> *curr=q.front().first;
            int curr_ind=q.front().second-mini;
            q.pop();
            if(i==0)
            first=curr_ind;
            if(i==size-1)
            last=curr_ind;
            if(curr->left)
            {
                q.push({curr->left,(long long)curr_ind*2+1});
            }
            if(curr->right)
            {
                q.push({curr->right,(long long)curr_ind*2+2});
            }

        }
        ans=max(ans,size);

    }
    return ans;
}