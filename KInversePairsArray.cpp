/*
For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].
Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

Example 1:
Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.

Example 2:
Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
*/

class Solution {
public:
    int dp[1001][1001];
    int mod = 1e9+7;
    long f(int n, int k){
        if(k<=0) return !k;
        if(n<=0) return 0;
        if(dp[n][k]!=-1) return dp[n][k];

        dp[n][k] = (f(n-1, k) + f(n, k-1))%mod;
        return dp[n][k] = (dp[n][k] - f(n-1, k-n) + mod)%mod;
    }
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return f(n,k);
    }
};
