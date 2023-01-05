/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
*/

class Solution {
public:
    bool helper(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i>=s.size() and j>=p.size()) return true;
        if(j>=p.size()) return false;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool ans=false;
        bool match = (i<s.size()) and (s[i]==p[j] or p[j]=='.');
        if(j+1<p.size() and p[j+1]=='*'){
            ans=(match and helper(s,p,i+1,j,dp)) or helper(s,p,i,j+2,dp);
        }else if(match){
            ans=helper(s,p,i+1,j+1,dp);
        }
    return dp[i][j]=ans;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size(), -1));
    return helper(s,p,0,0,dp);
    }
};
