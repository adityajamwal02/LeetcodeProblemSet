/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, ifyou are at nums[i], you can jump to any nums[i + j] where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2
*/

/// Recursion

class Solution {
public:
    int helper(int index, int n, vector<int> &nums){
        if(index==n-1){
            return 0;
        }
        int jump=nums[index], minsteps=1e9;
        for(int i=index+1;i<=min(index+jump, n-1);i++){
            int steps=1+helper(i,n,nums);
            minsteps=min(minsteps,steps);
        }
    return minsteps;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
    return helper(0,n,nums);
    }
};

/// Memoization

class Solution {
public:
    int helper(int index, int n, vector<int> &nums, vector<int> &dp){
        if(index==n-1){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }

        int jump=nums[index], minsteps=1e9;
        for(int i=index+1;i<=min(index+jump, n-1);i++){
            int steps=1+helper(i,n,nums,dp);
            minsteps=min(minsteps,steps);
        }
    return dp[index]=minsteps;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);

    return helper(0,n,nums,dp);
    }
};

/// Tabulation

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 0);
        for(int index=n-2;index>=0;index--){
            int jump=nums[index], minsteps=1e9;
            for(int i=index+1;i<=min(index+jump, n-1);i++){
                int steps=1+dp[i];
                minsteps=min(minsteps,steps);
            }
        dp[index]=minsteps;
        }

    return dp[0];
    }
};
