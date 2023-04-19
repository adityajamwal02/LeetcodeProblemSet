/*
A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top. As the answer will be large find the answer modulo 1000000007.

Example 1:
Input:
N = 1
Output: 1

Example 2:
Input:
N = 4
Output: 7
Explanation:Below are the 7 ways to reach
4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step
Your Task:
Your task is to complete the function countWays() which takes 1 argument(N) and returns the answer%(10^9 + 7).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/

/// Recursive case

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod=1e9+7;

    long long countWays(int n)
    {
        long long sum=0;
        if(n==0 or n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 4;
        for(int i=1;i<=3;i++){
            if(n>=i){
                sum+=countWays(n-i);
            }
        }
    return sum%((long long) 1e9+7);
    }
};

/// Memoization


class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod=1e9+7;

    long long helper(int n, vector<int> &dp){
        long long sum=0;

        if(n==0 or n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 4;

        if(dp[n]!=-1) return dp[n];

        for(int i=1;i<=3;i++){
            if(n>=i){
                sum+=helper(n-i,dp);
            }
        }
    return dp[n]=sum%((long long) 1e9+7);
    }

    long long countWays(int n)
    {
        vector<int> dp(n+1, -1);

    return helper(n,dp);
    }
};

/// Best Solution

int mod = 1e9+7;
long long countWays(int n)
{
    long long sum1=1,sum2=2,sum3=4;

    // f(n) = f(n-1) + f(n-2) + f(n-3)

    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    long long ways,t;
    for(int i = 4;i<=n;i++){
        ways = (sum1+sum2+sum3)%mod;

        t = sum2;
        sum2 = sum3;
        sum3 = ways;
        sum1 = t;
    }
    return ways;
}
