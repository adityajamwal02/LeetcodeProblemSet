/*
Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

Example 1:
Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation:
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.

Example 2:
Input: grid = [[7]]
Output: 7
*/

/// Recursion

class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i==n-1) return grid[i][j];
        if(i>=n or j>=n) return 1e9;
        int mini=1e9;
       // if(dp[i][j]!=-1) return dp[i][j];
        for(int k=0;k<n;k++){
            if(k!=j){
                mini=min(mini,grid[i][j]+solve(i+1,k,n,grid,dp));
            }
        }
    return mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int minVal=INT_MAX;
        for(int j=0;j<n;j++){
            minVal=min(minVal,solve(0,j,n,grid,dp));
        }
    return minVal;
    }
};

/// Memoization

class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i==n-1) return grid[i][j];
        if(i>=n or j>=n) return 1e9;
        int mini=1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=0;k<n;k++){
            if(k!=j){
                mini=min(mini,grid[i][j]+solve(i+1,k,n,grid,dp));
            }
        }
    return dp[i][j]=mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int minVal=INT_MAX;
        for(int j=0;j<n;j++){
            minVal=min(minVal,solve(0,j,n,grid,dp));
        }
    return minVal;
    }
};

/// Tabulation

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {

        int n = mat.size();
        vector<vector<int>> dp(n , vector<int> (n , INT_MAX));
        for(int i=0 ; i<n ; i++) dp[n-1][i] = mat[n-1][i];

        for(int i=n-2 ; i>=0 ; i--){
            for(int j=0 ; j<n ; j++){
                for(int k=0 ; k<n ; k++){
                    if(k!=j){
                        dp[i][j] = min(dp[i][j] , dp[i+1][k]+mat[i][j]);
                    }
                }
            }
        }
        return *min_element(dp[0].begin() , dp[0].end());
    }
};
