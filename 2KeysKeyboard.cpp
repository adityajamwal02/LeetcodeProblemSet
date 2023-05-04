/*
There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:
Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

Example 1:
Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Example 2:
Input: n = 1
Output: 0
*/

/// Recursion

class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        int minVal=INT_MAX;
        for(int i=2;i<=n;i++){
            if(n%i==0) minVal=min(minVal,i+minSteps(n/i));
        }
    return minVal;
    }
};


/// Memoization

class Solution {
public:
    int solve(int i, vector<int> &dp){
        if(i==1) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int minVal=INT_MAX;
        for(int j=2;j<=i;j++){
            if(i%j==0) minVal=min(minVal,j+solve(i/j,dp));
        }
    return dp[i]=minVal;
    }
    int minSteps(int n) {
        vector<int> dp(n+1,-1);
    return solve(n,dp);
    }
};

