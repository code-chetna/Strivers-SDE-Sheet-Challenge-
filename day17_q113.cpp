#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int>res(TreeNode *root,vector<int>&ans)
{
 if(root==NULL)
    {
        return ans;
    }
   
    res(root->left,ans);
    res(root->right,ans);
    ans.push_back(root->data);
    return ans;
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
   
    // Write your code here.
    vector<int>ans;
    return res(root,ans);

    
}