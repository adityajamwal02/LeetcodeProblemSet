/*
A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

Example 1:
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.

Example 2:
Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
*/

/// stack

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size(), width=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty() or nums[st.top()]>nums[i]){
                st.push(i);
            }
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums[st.top()]<=nums[i]){
                width=max(width,i-st.top());
                st.pop();
            }
        }
    return width;
    }
};
