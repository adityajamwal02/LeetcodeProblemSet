/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

/// Recursive Approach

class Solution {
public:
    int solve(int i, int j, string word1, string word2){
        if(j<0)
            return i+1;
        if(i<0)
            return j+1;
        if(word1[i]==word2[j])
            return solve(i-1,j-1,word1,word2);
        else{
            int insert=1+solve(i,j-1,word1,word2);
            int deleted=1+solve(i-1,j,word1,word2);
            int replace=1+solve(i-1,j-1,word1,word2);
         return min(min(insert,deleted),replace);
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
    return solve(n-1, m-1, word1, word2);
    }
};

/// Memoization

class Solution {
public:
    int solve(int i, int j, string word1, string word2,vector<vector<int>> &dp){
        if(j<0)
            return i+1;
        if(i<0)
            return j+1;
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(word1[i]==word2[j])
            return dp[i][j]=solve(i-1,j-1,word1,word2,dp);
        else{
            int insert=1+solve(i,j-1,word1,word2,dp);
            int deleted=1+solve(i-1,j,word1,word2,dp);
            int replace=1+solve(i-1,j-1,word1,word2,dp);
         return dp[i][j]=min(min(insert,deleted),replace);
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
    return solve(n-1, m-1, word1, word2,dp);
    }
};

// Tabulation

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n+1;i++){
            dp[i][0]=i;
        }
        for(int j=1;j<m+1;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    int insert = 1 + dp[i][j-1];
                    int deleted = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];
                    dp[i][j] = min(min(insert,deleted),replace);
                }
            }
        }
    return dp[n][m];
    }
};

// Space Optimization

  int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>prev(m+1,0),curr(m+1,0);

        for(int i=0;i<m+1;i++){
            prev[i]=i;
        }
        for(int i=1;i<n+1;i++){
            curr[0] = i;
            for(int j=1;j<m+1;j++){
                if(word1[i-1]==word2[j-1])
                    curr[j] = prev[j-1];
                else{
                    int insert = 1 + curr[j-1];
                    int deleted = 1 + prev[j];
                    int replace = 1 + prev[j-1];
                    curr[j] = min(min(insert,deleted),replace);
                }
            }
            prev = curr;
        }

        return prev[m];
    }
