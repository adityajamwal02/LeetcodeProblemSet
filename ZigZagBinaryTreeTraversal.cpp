/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        bool LTR=true;

        while(!q.empty()){
            int size=q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                int index=(LTR) ? i : size-1-i;
                row[index]=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            LTR=!LTR;
            result.push_back(row);
        }
    return result;
    }
};
