/*
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
*/


/// DP on Trees (Imp Question) --> Hard
/// DFS Solution (Starting to cover from the leaf nodes and attaching cameras to the second last node

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
    int cover(TreeNode* root, int &count){
        if(!root) return 1;
        int left=cover(root->left, count);
        int right=cover(root->right, count);
        if(left==0 or right==0){
            count++;
            return 2;
        }else if(left==2 or right==2){
            return 1;
        }
    return 0;
    }
    int minCameraCover(TreeNode* root) {
        int count=0;
        int minCam=cover(root, count);
        if(minCam==0) count++;
    return count;
    }
};


