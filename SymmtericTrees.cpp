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

    bool recursion(TreeNode* left, TreeNode* right)
    {
        if(left==NULL and right==NULL)
            return true;
        if((left==NULL and right!=NULL) || (left!=NULL and right==NULL) || (left->val!=right->val))
            return false;
        return recursion(left->left, right->right) and recursion(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return recursion(root->left, root->right);
    }

};
