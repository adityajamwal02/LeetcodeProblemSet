/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
*/

/// Recursion solution

class Solution {
public:
    int helper(int i, int j, string &p, string &s){
        if(i<0 and j<0)
            return true;
        if(i<0 and j>=0)
            return false;
        if(j<0 and i>=0){
            for(int k=0;k<=i;k++){
                if(p[k]!='*')
                    return false;
            }
        return true;
        }
    if(p[i]==s[j] or p[i]=='?'){
        return helper(i-1,j-1,p,s);
    }
    if(p[i]=='*'){
        return helper(i-1,j,p,s) or helper(i,j-1,p,s);
    }
    return false;
    }

    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        return helper(n-1,m-1,p,s);
    }
};

/// Memoization Solution

class Solution {
public:
    int helper(int i, int j, string &p, string &s,vector<vector<int>> &dp){
        if(i<0 and j<0)
            return true;
        if(i<0 and j>=0)
            return false;
        if(j<0 and i>=0){
            for(int k=0;k<=i;k++){
                if(p[k]!='*')
                    return false;
            }
        return true;
        }
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(p[i]==s[j] or p[i]=='?'){
        return dp[i][j]= helper(i-1,j-1,p,s,dp);
    }
    if(p[i]=='*'){
        return dp[i][j]=helper(i-1,j,p,s,dp) or helper(i,j-1,p,s,dp);
    }
    return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return helper(n-1,m-1,p,s,dp);
    }
};

/// Tabulation Method

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m;j++){
            dp[0][j]=false;
        }
        for(int i=1;i<=n;i++){
            int flag=true;
              for(int k=1;k<=i;k++){
                if(p[k-1]!='*')
                    flag=false;
            }
        dp[i][0]=flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1]==s[j-1] or p[i-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
                }
                else dp[i][j]=false;
                }
            }
        return dp[n][m];
        }
};
