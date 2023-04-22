/*
Given a String, find the longest palindromic subsequence.

Example 1:
Input:
S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.

Example 2:
Input:
S = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are
palindromic and all have a length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalinSubseq() which takes the string S as input and returns an integer denoting the length of the longest palindromic subsequence of S.

Expected Time Complexity: O(|S|*|S|).
Expected Auxiliary Space: O(|S|*|S|).
*/


/// Recursion

class Solution{
  public:
    int helper(string &A, int i, int j){
        if(i>j) return 0;
        else if(i==j) return 1;
        if(A[i]==A[j]){
            return 2+helper(A,i+1,j-1);
        }
        else{
            return max(helper(A,i+1,j),helper(A,i,j-1));
        }
    }
    int longestPalinSubseq(string A) {
        int n=A.size();
       // vector<
    return helper(A,0,n-1);
    }
};

/// Memoization

//User function Template for C++

class Solution{
  public:
    int helper(string &A, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        else if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(A[i]==A[j]){
            return dp[i][j]=2+helper(A,i+1,j-1,dp);
        }
        else{
            return dp[i][j]=max(helper(A,i+1,j,dp),helper(A,i,j-1,dp));
        }
    }
    int longestPalinSubseq(string A) {
        int n=A.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
    return helper(A,0,n-1,dp);
    }
};
