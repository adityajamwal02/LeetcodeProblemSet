/*
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Example 2:
Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

Example 3:
Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
*/

/// Brute Approach

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int res=nums[0];
        for(int i=0;i<n;i++){
            int curr_max=nums[i];
            int sum_max=nums[i];
            for(int j=1;j<n;j++){
                int index=(i+j)%n;
                sum_max+=nums[index];
                curr_max=max(curr_max,sum_max);
            }
        res=max(res,curr_max);
        }
    return res;
    }
};

/// Kadane Algorithm

class Solution {
public:
    int normalSum(vector<int> &nums){
        int n=nums.size();
        int res=nums[0], maxEnd=nums[0];
        for(int i=1;i<n;i++){
            maxEnd=max(nums[i], maxEnd+nums[i]);
            res=max(res,maxEnd);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxNormal=normalSum(nums);
        if(maxNormal<0){
            return maxNormal;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            nums[i]=-nums[i];
        }
        int maxCircular=sum+normalSum(nums);
        int ans=max(maxNormal,maxCircular);

    return ans;
    }
};
