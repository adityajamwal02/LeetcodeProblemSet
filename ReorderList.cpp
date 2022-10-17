/*
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
*/

/// Extra Space 2 pointer approach

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode *> arr;
        for(auto iter=head; iter; iter=iter->next)
            arr.push_back(iter);

        int l=1, r=size(arr)-1;
        for(int i=0;i<size(arr);i++, head=head->next){
            if(i&1)
                head->next=arr[l++];
            else
                head->next=arr[r--];
        }
        head->next=NULL;
    }
};


/// Stack Approach

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head or !head->next or !head->next->next)
            return;
        stack<ListNode*> st;
        ListNode *ptr=head;
        int size=0;
        while(ptr!=NULL){
            st.push(ptr);
            size++;
            ptr=ptr->next;
        }
        ListNode* pptr=head;
        for(int i=0;i<size/2;i++){
            ListNode *temp=st.top();
            st.pop();
            temp->next=pptr->next;
            pptr->next=temp;
            pptr=pptr->next->next;
        }
        pptr->next=NULL;
    }
};

