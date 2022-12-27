/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:
Input: matrix = [["0"]]
Output: 0
*/

/// Recursion

class Solution {
public:
    int maxi=0;
    int solve(vector<vector<char>> &matrix, int i, int j, int n, int m){
        if(i>=n or j>=m){
            return 0;
        }
        int right=solve(matrix,i,j+1,n,m);
        int diagnol=solve(matrix,i+1,j+1,n,m);
        int bottom=solve(matrix,i+1,j,n,m);
        if(matrix[i][j]=='1'){
            maxi=max(maxi, 1+min(right, min(diagnol,bottom)));
            return 1+min(right,min(diagnol,bottom));
        }else{
            return 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        solve(matrix,0,0,n,m);
    return maxi*maxi;
    }
};


/// Memoization

class Solution {
public:
    int maxi=0;
    int solve(vector<vector<char>> &matrix, int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i>=n or j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(matrix,i,j+1,n,m,dp);
        int diagnol=solve(matrix,i+1,j+1,n,m,dp);
        int bottom=solve(matrix,i+1,j,n,m,dp);
        if(matrix[i][j]=='1'){
            dp[i][j]=1+min(right, min(diagnol,bottom));
            maxi=max(maxi, dp[i][j]);
            return dp[i][j];
        }else{
            return 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        solve(matrix,0,0,n,m,dp);
    return maxi*maxi;
    }
};
