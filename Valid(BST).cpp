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
    vector<int> v;

    void inorderTraversal(TreeNode * root)
    {
        if(!root)
            return;
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
    }


    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        inorderTraversal(root);
        for(int i=1; i<v.size(); i++)
        {
            if(v[i]<=v[i-1])
                return false;
        }
     return true;
    }
};
