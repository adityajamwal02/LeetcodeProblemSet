/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/

/// Partial TestCases

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        int i=1, j=k-1, n=nums.size();
        vector<int> ans;
        int curr_max=nums[0];
        while(j<n){
            while(i<=j){
                curr_max=max(curr_max,nums[i]);
                i++;
            }
            ans.push_back(curr_max);
            i=j-1;
            j++;
        }
    return ans;
    }
};


/// Dequeue Problem

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k){
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() and dq.front()==i-k){
                dq.pop_front();
            }
            while(!dq.empty() and nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
    return ans;
    }
};

/// Sliding Window Solution

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k){
        int n=nums.size();
        vector<int> ans;
        deque<int> dq;
        int i=0, j=0;
        while(j<n){
            while(!dq.empty() and nums[j]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){
                ans.push_back(dq.front());
                if (dq.front() == nums[i]){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
