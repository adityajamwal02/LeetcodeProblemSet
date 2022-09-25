/*
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
*/



class Solution {
public:

    ListNode* getMid(ListNode* head){
        ListNode* midprev=NULL;
        while(head and head->next){
            midprev=(midprev==NULL) ? head : midprev->next;
            head=head->next->next;
        }
        ListNode* mid=midprev->next;
        midprev->next=NULL;
    return mid;
    }

    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;
        while(list1 and list2){
            if(list1->val < list2->val){
                ptr->next=list1;
                list1=list1->next;
            }else{
                ptr->next=list2;
                list2=list2->next;
            }
        ptr=ptr->next;
        }
        if(list1) ptr->next=list1;
        else ptr->next=list2;
    return dummyHead.next;
    }


    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode *mid=getMid(head);
        ListNode *left=sortList(head);
        ListNode *right=sortList(mid);

        return merge(left, right);
    }
};
