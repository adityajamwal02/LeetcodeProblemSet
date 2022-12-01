/*
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.

Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
*/

/// Recursion

class Solution {
public:
    int helper(int num, int sum){
        if(num==1){
            return 1;
        }
        int notpick=helper(num-1,sum);
        int pick=0;
        if(sum>=num){
            pick=num*helper(num,sum-num);
        }
        result=max(pick,notpick);
    }

    int integerBreak(int n) {
        return helper(n-1,n);
    }
};

/// Memoization

class Solution {
public:
    int helper(int num, int sum, vector<vector<int>> &dp){
        if(num==1){
            return 1;
        }
        if(dp[num][sum]!=-1){
            return dp[num][sum];
        }
        int notpick=helper(num-1,sum,dp);
        int pick=0;
        if(sum>=num){
            pick=num*helper(num,sum-num,dp);
        }
        return dp[num][sum]=max(pick,notpick);
    }

    int integerBreak(int n) {
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return helper(n-1,n,dp);
    }
};
