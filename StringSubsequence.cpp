/*
Given two strings S1 and S2, find the number of times the second string occurs in the first string, whether continuous or discontinuous.

Example 1:
Input:
S1 = geeksforgeeks
S2 = gks
Output: 4
Explaination: For the first 'g' there
are 3 ways and for the second 'g' there
is one way. Total 4 ways.
Your Task:
You don't need to read input or print anything. Your task is to complete the function countWays() which takes the string S1 and S2 as input parameters and returns the number of ways.

Expected Time Complexity: O(n*m)        [n and m are length of the strings]
Expected Auxiliary Space: O(n*m)
*/

// User function Template for C++

class Solution{
public:
    int solve(int i, int j, int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        if(j==m) return 1;
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(s1[i]==s2[j]){
            take=solve(i+1,j+1,n,m,s1,s2,dp);
        }
        int notTake=solve(i+1,j,n,m,s1,s2,dp);

    return dp[i][j]=take+notTake;
    }
    int countWays(string S1, string S2){
        int n=S1.size();
        int m=S2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    return solve(0,0,n,m,S1,S2,dp);
    }
};
