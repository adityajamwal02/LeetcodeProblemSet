/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned
as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: []
*/

/// Recursive Solution

class Solution {
public:
    vector<vector<int>> ans;

    void solve(TreeNode* root, int targetSum, vector<int> &path){
        if(!root)
            return;

        path.push_back(root->val);
        solve(root->left, targetSum,path);
        solve(root->right, targetSum, path);
        if(root->left==NULL and root->right==NULL){
            int sum=0;
            for(int i=0;i<path.size();i++){
                sum+=path[i];
            }
            if(sum==targetSum){
                ans.push_back(path);
            }
        }
        path.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root, targetSum, path);
        return ans;
    }
};
