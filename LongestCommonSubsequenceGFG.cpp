/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:
Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.

Example 2:
Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.
Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
*/

/// Recursion

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int helper(int i, int j, int x, int y, string &s, string &t){
        if(i>=x or j>=y) return 0;
        int ans=0;
        if(s[i]==t[j]){
            ans=1+helper(i+1,j+1,x,y,s,t);
        }else{
            return max(helper(i+1,j,x,y,s,t),helper(i,j+1,x,y,s,t));
        }
    return ans;
    }

    int lcs(int x, int y, string s1, string s2)
    {
        int result=helper(0,0,x,y,s1,s2);
    return result;
    }
};


/// Memoization

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int helper(int i, int j, int x, int y, string &s, string &t, vector<vector<int>> &dp){
        if(i>=x or j>=y) return 0;
        int ans=0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            ans=1+helper(i+1,j+1,x,y,s,t,dp);
        }else{
            return max(helper(i+1,j,x,y,s,t,dp),helper(i,j+1,x,y,s,t,dp));
        }
    return dp[i][j]=ans;
    }

    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x,vector<int> (y,-1));
        int result=helper(0,0,x,y,s1,s2,dp);
    return result;
    }
};


/// Tabulation

// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.

    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x+1,vector<int> (y+1,0));
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
       /* for(int i=0;i<=x;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=y;j++){
            dp[0][j]=0;
        }
       */
    return dp[x][y];
    }
};
