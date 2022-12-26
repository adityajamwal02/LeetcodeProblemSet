/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
Input: amount = 10, coins = [10]
Output: 1
*/

/// RECURSION

class Solution {
public:
    int helper(int i, int amount, vector<int> &coins){
        if(i==0){
            return (amount%coins[0]==0);
        }
        long notTake=helper(i-1,amount,coins);
        long Take=0;
        if(coins[i]<=amount){
             Take=helper(i,amount-coins[i],coins);
        }

    return (notTake+Take);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return helper(n-1,amount,coins);
    }
};

/// MEMOIZATION

class Solution {
public:
    int helper(int i, int amount, vector<int> &coins,vector<vector<int>> &dp){
        if(i==0){
            return (amount%coins[0]==0);
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        long notTake=helper(i-1,amount,coins,dp);
        long Take=0;
        if(coins[i]<=amount){
             Take=helper(i,amount-coins[i],coins,dp);
        }

    return dp[i][amount]=notTake+Take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,coins,dp);
    }
};

/// TABULATION

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int j=0;j<=amount;j++){
            dp[0][j]=(j%coins[0]==0);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                long notTake=dp[i-1][j];
                long Take=0;
                if(coins[i]<=j){
                    Take=dp[i][j-coins[i]];
                }
            dp[i][j]=Take+notTake;
            }

        }
    return dp[n-1][amount];
    }
};

/// Space Optimization

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> prev(amount+1,0), curr(amount+1,0);
        for(int j=0;j<=amount;j++){
            prev[j]=(j%coins[0]==0);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                long notTake=prev[j];
                long Take=0;
                if(coins[i]<=j){
                    Take=curr[j-coins[i]];
                }
            curr[j]=Take+notTake;
            }
        prev=curr;
        }
    return prev[amount];
    }
};

