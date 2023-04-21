/*
Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.

Example 1:
Input: n = 2
Output: 1
Explanation: 1 is the 2nd number
of fibonacci series.
Example 2:

Input: n = 5
Output: 5
Explanation: 5 is the 5th number
of fibonacci series.

Your Task:
You dont need to read input or print anything. Complete the function nthFibonacci() which takes n as input parameter and returns nth fibonacci number.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
*/

// User function Template for C++
class Solution {
  public:
    int mod=1e9+7;
    long long int helper(long long int n,vector<long long int> &dp){
        if(n<=0) return 0;
        if(n==1 or n==2) return 1;
        if(dp[n]!=-1) return dp[n];

    return dp[n]=(helper(n-1,dp)%mod+helper(n-2,dp)%mod)%mod;
    }

    long long int nthFibonacci(long long int n){
        vector<long long int> dp(n+1,-1);
        long long int result = helper(n,dp);
    return result%mod;
    }
};
