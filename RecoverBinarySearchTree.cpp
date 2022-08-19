/*
You are given the root of a binary search tree (BST),
where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
*/

class Solution {
private:
    TreeNode* first;
    TreeNode* last;
    TreeNode* prev;
    TreeNode* middle;

    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);

        if(prev!=NULL and (root->val<prev->val)){
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first and last)
            swap(first->val, last->val);
        else if(first and middle)
            swap(first->val, middle->val);
    }
};
