/*
You are given the head of a linked list.
Remove every node which has a node with a strictly greater value anywhere to the right side of it.
Return the head of the modified linked list.

Example 1:
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

Example 2:
Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
*/

/// Without Recursion (Stack based)

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
    ListNode* removeNodes(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }
        stack<int> st;
        int n=nums.size();
        st.push(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=st.top()){
                st.push(nums[i]);
            }else{
                continue;
            }
        }
        ListNode* temp= new ListNode(st.top());
        st.pop();
        ListNode* end=temp;
        while(!st.empty()){
            end->next = new ListNode(st.top());
            st.pop();
            end=end->next;
        }
    return temp;
    }
};
