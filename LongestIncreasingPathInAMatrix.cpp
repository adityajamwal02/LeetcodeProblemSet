/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Example 1:
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:
Input: matrix = [[1]]
Output: 1
*/


class Solution {
public:
    int dp[200][200]={0};
    int n,m
    int dfs(vector<vector<int>>& matrix, int i, int j, int p){
        if(i<0 or j<0 or i>=n or j>=m or matrix[i][j]<=p){
            return 0;
        }
        if(dp[i][j]){
            return dp[i][j];
        }
        p=matrix[i][j];
        return dp[i][j]=1+max({dfs(matrix,i+1,j,p), dfs(matrix,i-1,j,p), dfs(matrix,i,j+1,p), dfs(matrix,i,j-1,p)});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dfs(matrix,i,j,-1));
            }
        }
    return ans;
    }
};
