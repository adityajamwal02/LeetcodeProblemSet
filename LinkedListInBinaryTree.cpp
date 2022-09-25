/*
Given a binary tree root and a linked list with head as the first node.
Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree
otherwise return False. In this context downward path means a path that starts at some node and goes downwards.

Example 1:
Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.

Example 2:
Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true

Example 3:
Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
*/


class Solution {
public:
    bool path(TreeNode* temp, ListNode* curr){
        if(curr==NULL)
            return true;
        if(temp==NULL)
            return false;
        if(temp->val==curr->val)
            return path(temp->left, curr->next) or path(temp->right, curr->next);
        else
            return false;
    }

    bool traversal(TreeNode* temp, ListNode* curr){
        bool result;
        if(temp==NULL)
            return false;
        if(temp->val==curr->val){
            result = path(temp->left, curr->next) or path(temp->right, curr->next);
        }
        return result or traversal(temp->left, curr) or traversal(temp->right, curr);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return traversal(root, head);
    }
};
