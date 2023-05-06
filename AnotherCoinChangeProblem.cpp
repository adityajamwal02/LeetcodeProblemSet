/*
Given three integers n, k, target, and an array of coins of size n. Find if it is possible to make a change of target cents by using an infinite supply of each coin but the total number of coins used must be exactly equal to k.

Example 1:
Input:
n = 5, k = 3, target = 11
coins = {1, 10, 5, 8, 6}
Output:
1
Explanation:
2 coins of 5 and 1 coins of 1 can be used
to make change of 11 i.e. 11 => 5+5+1.

Example 2:
Input:
n = 3, k = 5, target = 25
coins = {7, 2, 4}
Output:
1
Explanation:
3 coins 7, 2 coins of 2 can be used to
make change of 25 i.e. 25 => 7+7+7+2+2.

Your Task:
This is a function problem. You only need to complete the function makeChanges() that 3 integers n, k, target, and an array coins as parameters and return True or False.

Expected Time Complexity: O(n*k*target)
Expected Space Complexity: O(k*target)
*/

class Solution {
  public:
    bool helper(int i, int n, int k, int target, vector<int> &coins, vector<vector<vector<int>>> &dp){
        if(i==n) return false;
        if(!k) return !target;
        if(dp[i][k][target]!=-1){
            return dp[i][k][target];
        }
        bool notPick=helper(i+1,n,k,target,coins,dp);
        bool pick=target-coins[i]>=0 ? helper(i+1,n,k-1,target-coins[i],coins,dp) or helper(i,n,k-1,target-coins[i],coins,dp) : false;
    return dp[i][k][target] = pick or notPick;
    }

    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(K+1, vector<int>(target+1, -1)));
    return helper(0,N,K,target,coins,dp);
    }
};
