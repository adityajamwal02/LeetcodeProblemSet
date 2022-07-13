/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        ans.clear();
        if(root)
            traverse(root, 0);

        return ans;

    }
};
