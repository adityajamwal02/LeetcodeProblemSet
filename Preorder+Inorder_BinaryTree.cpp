/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree
and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]
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

    TreeNode* solve(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap){
        if(preStart>preEnd or inStart>inEnd)
            return NULL;

        TreeNode * root= new TreeNode(preorder[preStart]);
        int inRoot=inMap[root->val];
        int numsLeft=inRoot-inStart;
        root->left=solve(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
        root->right=solve(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);

    return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;

        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]]=i;

        TreeNode* root=solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
    return root;
    }
};

