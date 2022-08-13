/*
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values.
(i.e., from left to right, level by level from leaf to root).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
*/

class Solution {
public:
  vector<vector<int>> ans;

    void traverse(TreeNode*root,int level)
    {
        if(ans.size()<=level)
        {
            vector<int> temp{root->val};
            ans.push_back(temp);
        }
        else{
            ans[level].push_back(root->val);
        }
        if(root->left)
            traverse(root->left, level+1);
        if(root->right)
            traverse(root->right, level+1);

    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        ans.clear();
        if(root)
            traverse(root, 0);

        reverse(ans.begin(),ans.end());

        return ans;

    }
};
