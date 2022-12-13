/*
The Tribonacci sequence Tn is defined as follows:
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.

Example 1:
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:
Input: n = 25
Output: 1389537
*/


/// Recursion

class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1 or n==2){
            return 1;
        }
    return tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
    }
};


/// Memoization

class Solution {
public:
    int helper(int i,vector<int> &dp){
        if(i==0){
           dp[i]=0;
        }
        if(i==1 or i==2){
            dp[i]=1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
    return dp[i]=helper(i-1,dp)+helper(i-2,dp)+helper(i-3,dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
    return helper(n,dp);
    }
};
