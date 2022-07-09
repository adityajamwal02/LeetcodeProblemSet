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
     void travel(TreeNode *root, vector<int> &v)
        {
         if(root==NULL)
             return;

        travel(root->left, v);
        v.push_back(root->val);
        travel(root->right, v);

         return;
        }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        travel(root, v);
        return v;
    }
};
