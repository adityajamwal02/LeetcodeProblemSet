/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]
*/

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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head or !head->next){
            return head;
        }
        ListNode *temp = head;
        vector<int> v1;
        while(temp){
            if(temp->val<x){
                v1.push_back(temp->val);
            }
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(temp->val>=x){
                v1.push_back(temp->val);
            }
            temp=temp->next;
        }
        ListNode* start = new ListNode(v1[0]);
        ListNode* end = start;
        for(int i=1;i<v1.size();i++){
            end->next = new ListNode(v1[i]);
            end=end->next;
        }
    return start;
    }
};
