/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes)
where the null nodes between the end-nodes that would be present in a complete binary tree
extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;

        long ans=0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            long size=q.size();
            long first, last;
            long mmin=q.front().second;
            for(int i=0;i<size;i++){
                long curr=q.front().second-mmin;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)
                    first=curr;
                if(i==size-1)
                    last=curr;
                if(node->left)
                    q.push({node->left, curr*2+1});
                if(node->right)
                    q.push({node->right, curr*2+2});
            }
            ans=max(ans, last-first+1);
        }
    return ans;
    }
};
