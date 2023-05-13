/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none)
of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
*/

/// Brute Force Approach

class Solution {
public:
    bool isSubsequence(string s, string t) {
    int j = 0;
    for (int i = 0; i < t.length() && j < s.length(); i++)
        if (s[j] == t[i])
            j++;

    return (j == s.length());
    }
};


/// Recursive Approach

class Solution {
public:

    bool isSubs(string& s, string& t, int m, int n)
    {
        if(m == 0)
            return true;
        if(n == 0)
            return false;

        if (s[m - 1] == t[n - 1])
            return isSubs(s, t, m - 1, n - 1);

        return isSubs(s, t, m, n - 1);
    }


    bool isSubsequence(string s, string t) {

       if( isSubs(s,t,s.length(),t.length()))
           return true;

        return false;

    }
};

/// Memoization Technique (Using concept of LCS in string s and t) then comparing if LCS size equal to string s size

class Solution {
public:

    int isSubs(string& s, string& t, int i , int j, vector<vector<int>> &dp)
    {
        if(i == 0 || j == 0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i-1]==t[j-1])
            return dp[i][j] = 1 + isSubs(s,t,i-1,j-1,dp);
        else
            return dp[i][j] = isSubs(s,t,i,j-1,dp);
    }


    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();

        if(m>n)
            return false;

        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));

        if(isSubs(s,t,m,n,dp) == m)
            return true;

        return false;
    }
};

/// Stack Approach

class Solution {
    public:
        bool isSubsequence(string s, string t)
        {
            for(int x=t.size()-1; x>=0 && !s.empty(); x--)
                if (t[x]==s[s.size()-1]) s.pop_back();   //treating subsequence string as a stack
            return s.empty();
        }
};

/// 2 pointers

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(), m=t.size();
        if(n>m or (n==m and s!=t)) return false;
        int i=0, j=0;
        while(i<n and j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }else if(s[i]!=t[j]){
                j++;
            }
        }
    return i==n;
    }
};
