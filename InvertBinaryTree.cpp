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

 //APPROACH 1 (Directly)

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        if(!root)
            return root;

        if(root)
        {
            TreeNode* temp = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(temp);
        }

        return root;
    }
};


//APPROACH 2 (SWAP CHILD)

class Solution {
public:

    void swapchild(TreeNode* parent)
    {
        if(parent)
        {
            swapchild(parent->left);
            swapchild(parent->right);
            swap(parent->left, parent->right);
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        swapchild(root);

        return root;
    }
};
