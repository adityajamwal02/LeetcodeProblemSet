/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right.
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
*/

/// Memoization

class Solution {
public:

    int solve(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(j<0 or j>=n)
            return 1e9;
        if(i==0)
            return matrix[0][j];
        if(dp[i][j]!=-1)
            return dp[i][j];

        int up=matrix[i][j]+solve(i-1,j,n,matrix,dp);
        int leftdiagnol=matrix[i][j]+solve(i-1,j-1,n,matrix,dp);
        int rightdiagnol=matrix[i][j]+solve(i-1,j+1,n,matrix,dp);

    return dp[i][j]=min(up,min(leftdiagnol,rightdiagnol));
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int mini=1e8;
        for(int j=0;j<n;j++)
        {
            mini=min(mini, solve(n-1, j, n, matrix, dp));
        }
    return mini;
    }
};


/// Tabulation



