#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int>res(TreeNode<int> *root,int level,vector<int>&ans)
{
    if(root==NULL)
    return ans;

    if(ans.size()==level)
    ans.push_back(root->data);

    res(root->left,level+1,ans);
    res(root->right,level+1,ans);


    return ans;
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int>ans;
    return res(root,0,ans);

}