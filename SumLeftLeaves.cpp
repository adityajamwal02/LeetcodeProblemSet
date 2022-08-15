/*
Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int leftsum=0;
        if(!root)
            return 0;

        if(root->left and !root->left->left and !root->left->right)
            leftsum=root->left->val;

        return leftsum+sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};
