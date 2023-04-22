/*
Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.
A Palindrome String is one that reads the same backward as well as forward.

Example 1:
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Example 2:
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
*/

/// Recursion -> memoization (LCS (palindrome) Approach)


class Solution {
public:
    int longestPalindromeSubstring(string &s, int i, int j){
        if(i>j) return 0;
        else if(i==j) return 1;
        else if(s[i]==s[j]){
            return 2+longestPalindromeSubstring(s,i+1,j-1);
        }
        else{
            return max(longestPalindromeSubstring(s,i+1,j), longestPalindromeSubstring(s,i,j-1));
        }
    }
    int minInsertions(string s) {
        int n=s.size();
        int result = n - longestPalindromeSubstring(s,0,n-1);
    return result;
    }
};

/// Memoization

class Solution {
public:
    int longestPalindromeSubstring(string &s, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        else if(i==j) return 1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j]=2+longestPalindromeSubstring(s,i+1,j-1,dp);
        }
        else{
            return dp[i][j]=max(longestPalindromeSubstring(s,i+1,j,dp), longestPalindromeSubstring(s,i,j-1,dp));
        }
    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int result = n - longestPalindromeSubstring(s,0,n-1,dp);
    return result;
    }
};

/// LCS Approach (Tabulation);

class Solution {
    //same as find the longest sub palindrome subsequence
    public int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (s[i]==s[n-1-j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                } else {
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return n - dp[n][n];
    }
}
