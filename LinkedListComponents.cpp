/*
You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.
Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.

Example 1:
Input: head = [0,1,2,3], nums = [0,1,3]
Output: 2
Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.

Example 2:
Input: head = [0,1,2,3,4], nums = [0,3,1,4]
Output: 2
Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int count=0;
        ListNode *temp;
        temp=head;
        while(temp!=NULL){
            if(mp[temp->val]==1){
                count++;
                while(mp[temp->val]){
                    temp=temp->next;
                    if(temp==NULL){
                        return count;
                    }
                }
            }
        temp=temp->next;
        }
    return count;
    }
};



/// 2nd Solution
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode* temp=head;
        unordered_set<int> mp;
        for(int i=0;i<nums.size();i++){
            mp.insert(nums[i]);
        }
        int res=0;
        int cnt=0;
        while(temp!=NULL){
            if(mp.find(temp->val)!=mp.end()){
                cnt++;
            }
            else{
                if(cnt>=1){
                    res++;
                    cnt=0;
                }
            }
            temp=temp->next;
        }
        if(cnt>=1){
            res++;
        }
        return res;
    }
};
