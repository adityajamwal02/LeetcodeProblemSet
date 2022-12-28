/*
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
*/

class Solution {
public:
    int lcs(string s, string t){
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
        for(int i=0;i<=n;i++)
            dp[i][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(), s.end());
    return lcs(s,t);
    }
};
