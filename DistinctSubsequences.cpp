/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit

Example 2:
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
*/


/// Memoization

class Solution {
public:
    int helper(string s,string t,int i,int j,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=helper(s,t,i-1,j-1,dp)+helper(s,t,i-1,j,dp);
        }
        else{
            return dp[i][j]=helper(s,t,i-1,j,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
    return helper(s,t,n-1,m-1,dp);
    }
};

/// Tabulation

class Solution {
public:

    int numDistinct(string s1, string s2) {
        int prime = 1e9+7;
        int m = s1.length();
        int n = s2.length();
        int k = max(m,n);
        vector<int> prev(k+1,0);

      prev[0]=1;

      for(int i=1;i<m+1;i++){
          for(int j=n;j>=1;j--){
                if(s1[i-1]==s2[j-1]){
                    prev[j] =  (prev[j-1]+prev[j])%prime;
                }
          }
      }
      return prev[n];
    }
};
