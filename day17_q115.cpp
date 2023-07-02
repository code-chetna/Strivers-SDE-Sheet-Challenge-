#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int>ans;
    if(root==NULL)
    return ans;
    queue<pair<BinaryTreeNode<int>*,int>>q;
     map<int,int>mp;
     q.push({root,0});
    while(!q.empty())
    {
        BinaryTreeNode<int>*node=q.front().first;
        int line=q.front().second;
        if(node->left!=NULL)
        {
            q.push({node->left,line-1});
        }
         if(node->right!=NULL)
        {
            q.push({node->right,line+1});
        }
        q.pop();
        mp[line]=node->data;

    }
    for(auto it:mp)
    {
        ans.push_back(it.second);
    }
return ans;

    // Write your code here.
    
}
