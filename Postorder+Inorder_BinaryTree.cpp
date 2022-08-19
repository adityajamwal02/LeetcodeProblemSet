/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree
and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]
*/

class Solution {
private:
    vector<int> inorder, postorder;
    unordered_map<int, int> mp;

    TreeNode* helper(int i, int j, int ind){
        if(i > j) return NULL;

        TreeNode* root = new TreeNode(postorder[ind]);

		int index=mp[postorder[ind]];

        root->right = helper(index+1, j, ind-1);
        root->left = helper(i, index-1, ind - (j-index) - 1);

        return root;
    }
public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        this->inorder=inorder;
        this->postorder=postorder;

        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;

        return helper(0, inorder.size() - 1, inorder.size() - 1);
    }
};
