/*
The task is to count all the possible paths from top left to bottom right of a m X n matrix with the constraints that from each cell you can either move only to right or down.

Example 1:
Input: m = 2, n = 2
Output: 2
Explanation: Two possible ways are
RD and DR.

Example 2:
Input: m = 3, n = 3
Output: 6
Explanation: Six possible ways are
RRDD, DDRR, RDDR, DRRD, RDRD, DRDR.

Your Task:
You dont need to read input or print anything. Complete the function numberOfPaths() which takes m and n as input parameter and returns count all the possible paths.The answer may be very large, compute the answer modulo 109 + 7.

Expected Time Complexity: O(m*n)
Expected Auxiliary Space: O(m*n)
*/

// User function Template for C++
class Solution {
  public:
   long long int mod=1e9+7;

    long long int numberOfPaths(int m, int n){
        long long int dp[m][n];
        for(int i = 0;i<m;i++)
        {
            for(int j= 0;j<n;j++)
            {
                if(i==0||j==0)
                dp[i][j]=1;
            }
        }
        for(int i =1;i<m;i++)
        {
            for(int j =1;j<n;j++)
            {
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
        return dp[m-1][n-1];
    }
};
