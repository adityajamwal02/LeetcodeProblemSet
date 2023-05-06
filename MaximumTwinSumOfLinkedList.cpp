/*
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.
Given the head of a linked list with even length, return the maximum twin sum of the linked list.

Example 1:
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6.

Example 2:
Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7.

Example 3:
Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
*/

/// Extra O(n) space + Linear Time (O(n/2))

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
    int pairSum(ListNode* head) {
        if(!head) return NULL;
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }
        int i=0, j=nums.size()-1;
        int result=INT_MIN;
        while(i<j){
            int temp=nums[i]+nums[j];
            result=max(result,temp);
            j--;
            i++;
        }
    return result;
    }
};


/// Optimal Solution (O(n) Time + O(1))

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
    void reverse(ListNode** node){
        ListNode *curr=*node, *prev=0, *nxt;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
    *node=prev;
    }

    int pairSum(ListNode* head) {
        ListNode *prev=0, *slow=head, *fast=head;
        while(fast and fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=0;
        reverse(&slow);
        int result=INT_MIN;
        ListNode *ptr1=head, *ptr2=slow;
        while(ptr1){
            result=max(result,ptr1->val+ptr2->val);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    return result;
    }
};


