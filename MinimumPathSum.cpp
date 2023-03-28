/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/

/// Memoization

class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i==0 && j==0)
            return grid[0][0];
        if(i<0 || j<0)
            return 1e9;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=grid[i][j]+solve(i-1,j,grid,dp);
        int left=grid[i][j]+solve(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};

/// Tabulation

class Solution {
public:
        int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 and j==0)
                dp[i][j]=grid[i][j];
            else{
                int up=grid[i][j];
                int left=grid[i][j];
                if(i>0)
                    up+=dp[i-1][j];
                else
                    up=1e9;
                if(j>0)
                    left+=dp[i][j-1];
                else
                    left=1e9;

                dp[i][j]=min(left, up);
                }
            }
       }
    return dp[n-1][m-1];
    }
};
