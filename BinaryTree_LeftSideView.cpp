
class Solution{

public:
    vector<int> leftSideView(TreeNode* root){
        vector<int> ans;
        helper(root, 0, ans);

        return ans;
    }

    void helper(TreeNode* root,int level,vector<int> &ans){
        if(root==NULL)
            return ;
        if(ans.size()==level)
            ans.push_back(root->val);

        helper(root->left, level+1, ans);
        helper(root->right, level+1, ans);
    }
};
