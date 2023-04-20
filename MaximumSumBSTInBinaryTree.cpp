/*
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

Example 2:
Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.

Example 3:
Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
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

class NodeValue {
public:
    int minNode, maxNode, maxSum;

    NodeValue(int minNode, int maxNode, int maxSum)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};

class Solution {

private:
    NodeValue maxSumBSTHelper(TreeNode* root)
    {
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);

        if(left.maxNode < root->val && root->val < right.minNode)
        {
            //if BT is BST
            sum = max(sum, root->val + left.maxSum + right.maxSum);

            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), root->val + left.maxSum + right.maxSum);

        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }

public:
    int sum=0;
    int maxSumBST(TreeNode* root)
    {
        maxSumBSTHelper(root);
        return sum>0 ? sum : 0;

    }
};
