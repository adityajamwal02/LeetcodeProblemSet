/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

Example 1:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
*/

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
    int count;
    void solve(TreeNode* node, int targetSum){
        if(!node){
            return;
        }
        checkSum(node,targetSum);
        solve(node->left,targetSum);
        solve(node->right,targetSum);
    }
    void checkSum(TreeNode* node, long long targetSum){
        if(!node){
            return;
        }
        if(targetSum-node->val==0){
            count++;
        }
        checkSum(node->left,targetSum-node->val);
        checkSum(node->right,targetSum-node->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        count=0;
        solve(root,targetSum);
    return count;
    }
};
