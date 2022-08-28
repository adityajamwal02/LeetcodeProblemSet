/*
Given the head of a linked list, rotate the list to the right by k places.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k==0)
            return head;
        ListNode* fast=head;
        int size=1;
        while(fast->next and size++){
            fast=fast->next;
        }
        fast->next=head;
        k=k%size;
        k=size-k;
        while(k--){
            fast=fast->next;
        }
        head=fast->next;
        fast->next=NULL;

    return head;
    }
};
