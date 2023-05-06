/*
Consider a N x N grid with indexes of top left corner as (0, 0). Dyck path is a staircase walk from bottom left, i.e., (N-1, 0) to top right, i.e., (0, N-1) that lies above the diagonal cells (or cells on line from bottom left to top right).
The task is to count the number of Dyck Paths from (N-1, 0) to (0, N-1).
Here are the some of the possible paths for different N.

Example 1:
Input:
N = 4
Output:
14
Explanation:
Refer to the diagram above.

Example 2:
Input:
N = 3
Output:
5
Explanation:
Refer to the diagram above.

Your Task:
You don't need to read input or print anything. Your task is to complete the function dyckPaths() which takes an Integer N as input and returns the answer.
*/


/// Recursive


class Solution {
  public:
    long long dyckPaths(int N) {
        if(N<=1) return 1;
        long long result=0;
        for(int i=0;i<N;i++){
            result+=(dyckPaths(i)*dyckPaths(N-i-1));
        }
    return result;
    }
};


/// Tabulation


class Solution {
  public:
    long long dyckPaths(int N) {
        vector<long long> dp(N+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=N;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
    return dp[N];
    }
};

/// Linear Time (Binomial Expansion)

#include<bits/stdc++.h>
using namespace std;


unsigned long int binomialCoeff(unsigned int n, unsigned int k){

    unsigned long int result=1;
    if(k>n-k){
        k=n-k;
    }
    for(int i=0;i<k;i++){
        result*=(n-i);
        result/=(i+1);
    }
    return result;
}


unsigned long int catalan(unsigned int n){
    unsigned long int c=binomialCoeff(2*n,n);
    return c/(n+1);
}


