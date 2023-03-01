/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a
height-balanced binary search tree.

Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:
Input: head = []
Output: []
*/

/// Vector Based Approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }
    return helper(nums,0, nums.size()-1);
    }

    TreeNode* helper(vector<int> &nums, int left, int right){
        if(left>right)
            return NULL;

        int mid=(left+right)/2;
        TreeNode *temp = new TreeNode(nums[mid]);

        temp->left=helper(nums, left, mid-1);
        temp->right=helper(nums, mid+1, right);
    return temp;
    }
};


/// Fast and Slow Pointer Based Approach

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        auto slow=head;
        auto fast=head;
        auto prev=head;
        while(fast and fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=0;
        TreeNode* temp = new TreeNode(slow->val);
        temp->left=sortedListToBST(head);
        temp->right=sortedListToBST(slow->next);
    return temp;
    }
};
