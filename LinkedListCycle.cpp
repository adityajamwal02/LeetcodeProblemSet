/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // Floyd’s Cycle-Finding Algorithm // fast slow approach // 2 pointers // "tortoise and the hare algorithm"//

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;

        ListNode *fast = head;
        ListNode *slow = head;

         while(fast != NULL && fast ->next != NULL)
         {
            fast=fast->next->next;
            slow=slow->next;

            if(fast==slow)
                return true;
        }

    return false;
    }
};
