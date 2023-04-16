/*
Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].
Note: Assume that you have an infinite supply of each type of coin.

Example 1:
Input:
sum = 4 ,
N = 3
coins[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

Example 2:
Input:
Sum = 10 ,
N = 4
coins[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5}
and {5,5}.

Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which accepts an array coins[ ] its size N and sum as input parameters and returns the number of ways to make change for given sum of money.

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum)
*/


/// Recursive + memoization

class Solution {
  public:
    long long solve(int sum,int i,vector<vector<long long>>& dp,int coins[])
      {
          if(sum==0) return 1;
          if(sum<0) return 0;
          if(i<0) return 0;

          if(dp[i][sum]!=-1) return dp[i][sum];

          dp[i][sum]=solve(sum-coins[i],i,dp,coins)+solve(sum,i-1,dp,coins);
          return dp[i][sum];
      }

     long long int count(int coins[], int N, int sum) {

           vector<vector<long long>> dp(N,vector<long long>(sum+1,-1));
           return solve(sum,N-1,dp,coins);

    }
};

/// Tabulation

long long dp[sum+1][N+1];
    for(int i=0;i<=N;i++)dp[0][i]=1;
    for(int i=1;i<=sum;i++)dp[i][0]=0;

    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=N;j++)
        {
            dp[i][j]=dp[i][j-1];
            if(coins[j-1]<=i)
            dp[i][j]=dp[i][j]+dp[i-coins[j-1]][j];
        }
    }
    return dp[sum][N];
