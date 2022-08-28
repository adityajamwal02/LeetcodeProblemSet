/*
Given the head of a singly linked list, return true if it is a palindrome.
Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
*/


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=slow;
        ListNode* prev=NULL;
        ListNode* next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* first=head;
        while(prev!=NULL){
            if(first->val!=prev->val)
                return false;
            first=first->next;
            prev=prev->next;
        }
    return true;
    }
};
