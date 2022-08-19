/*
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the
BST such that their sum is equal to the given target.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
*/

class Solution {
    unordered_set<int> us;
    void getAllLeaves(TreeNode* node)
    {
        if(node == nullptr) return;
        us.insert(node->val);
        getAllLeaves(node->left);
        getAllLeaves(node->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        getAllLeaves(root);
        for(auto it = us.begin(); it != us.end(); it++)
            if(k - *it != *it && us.find(k - *it) != us.end()) return true;
        return false;
    }
};
