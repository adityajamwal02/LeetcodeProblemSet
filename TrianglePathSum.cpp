/*
Given a triangle array, return the minimum path sum to reach from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:
Input:
n = 4
triangle = [[2],
           [3,4],
          [6,5,7],
         [4,1,8,3]]
Output:
11
Explanation:
     2
   3 4
  6 5 7
 4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11.

Example 2:
Input:
n =  1
triangle = [[10]]
Output:
10
Your Task:
You don't have to read input or print anything. Your task is to complete the function minimizeSum() which takes integer n and the triangle and returns the minimum sum to reach from top to bottom.

Constraint:
1 <= triangle.length <= 200
triangle[i].length =  triangle[i-1].length + 1
1 <= triangle[i][j] <= 1000

Expected Time Complexity: O(n * n)
Expected Space Complexity: O(n* n)
*/

/// Memoization

class Solution {
  public:
    int helper(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        if(i==0) return triangle[0][0];
        if(i<0 or j<0 or j>=triangle[i].size()) return 1e9;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=triangle[i][j]+helper(i-1,j,n,triangle,dp);
        int right=triangle[i][j]+helper(i-1,j-1,n,triangle,dp);
    return dp[i][j]=min(up,right);
    }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int result=INT_MAX;
        for(int i=0;i<triangle[n-1].size();i++){
            result=min(result,helper(n-1,i,n,triangle,dp));
        }
    return result;
    }
};

/// Tabulation

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,10001));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j]=triangle[i][j]+dp[i-1][j];
                if(j>0){
                    dp[i][j]=min(dp[i][j], triangle[i][j]+dp[i-1][j-1]);
                }
            }
        }
    return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
