/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.

Example 1:

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
*/

class Solution {
public:

    int maxPath(TreeNode* node, int &maxsum){
        if(!node)
            return 0;
        int left=max(0, maxPath(node->left, maxsum));
        int right=max(0, maxPath(node->right, maxsum));
        maxsum=max(maxsum, left+right+node->val);

        return max(left, right)+node->val;
    }


    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        maxPath(root, maxsum);

        return maxsum;
    }
};
