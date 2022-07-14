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
    vector<int> v;

    vector<int> inorderTraversal(TreeNode* root)
    {
        if(root==NULL)
            return v;
        if(root->left==NULL and root->right==NULL)
        {
            v.push_back(root->val);
            return v;
        }
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);

        return v;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> V=inorderTraversal(root);
        int j=V.size()-1;
        int i=0;
        while(i<j){
            if(V[i]+V[j]==k){
                return true;
            }
            else if(V[i]+V[j]>k){
                j--;
            }
            else{
                i++;
            }
        }
    return false;
   }
};
