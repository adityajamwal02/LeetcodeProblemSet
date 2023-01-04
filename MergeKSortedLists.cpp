/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        int step=1;
        while(step<n){
            for(int i=0;i+step<n;i+=(step*2))
                lists[i]=merge(lists[i],lists[i+step]);
            step*=2;
        }
    return n>0 ? lists[0] : NULL;
    }

    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* temp=new ListNode();
        ListNode* curr=temp;
        while(list1 and list2){
            if(list1->val < list2->val){
                curr->next=list1;
                list1=list1->next;
            }else{
                curr->next=list2;
                list2=list2->next;
            }
        curr=curr->next;
        }
         curr->next=list1?list1:list2;
    return temp->next;
    }

};
