/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

Example 1:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:
Input: n = 1
Output: [[1]]
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
    vector<TreeNode*> helper(int start, int end){
        if(start>end) return {NULL};
        vector<TreeNode*> res;
        for(int i=start;i<=end;i++){
            for(auto left: helper(start, i-1)){
                for(auto right: helper(i+1, end)){
                    res.push_back(new TreeNode(i,left,right));
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};
