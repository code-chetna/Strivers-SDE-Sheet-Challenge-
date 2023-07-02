#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
vector<int>ans;
    if(root==NULL)
    return ans;
queue<pair<TreeNode<int>*,int>>q;
map<int,int>mp;
q.push({root, 0}) ;
while (!q.empty()) {
  TreeNode<int> *node = q.front().first;
  int line = q.front().second;
  q.pop();
  if (node->left != NULL) {
    q.push({node->left, line - 1});
  }
  if (node->right != NULL) {
    q.push({node->right, line + 1});
  }
  if(mp.find(line)==mp.end())
  {
      mp[line]=node->val;
  }
}
for(auto it:mp)
{
    ans.push_back(it.second);
}
return ans;
}