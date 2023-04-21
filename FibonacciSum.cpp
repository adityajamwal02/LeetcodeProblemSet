/*
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation

Given a number positive number N, find value of f0 + f1 + f2 + . + fN where fi indicates ith Fibonacci number.
Remember that f0 = 0, f1 = 1, f2 = 1, f3 = 2, f4 = 3, f5 = 5,
Since the answer can be very large, answer modulo 1000000007 should be returned.

Example 1:

Input:
N = 3
Output:
4
Explanation:
0 + 1 + 1 + 2  = 4
Example 2:

Input :
N = 4
Output :
7
Explanation :
0 + 1 + 1 + 2 + 3 = 7

Your Task:
You don't need to read input or print anything. Your task is to complete the function fibSum() which takes an integer N as input parameter and returns the sum of all the Fibonacci number from F0 to FN.

Expected Time Complexity: O(Log N)
Expected Space Complexity: O(1)

*/

class Solution{
public:
    int mod=1e9+7;
   long long int fibSum(long long int n){
         vector<long long int> dp(n+1,0);
         dp[0]=0;
         dp[1]=1;
         long long int result=0;
         for(int i=2;i<=n;i++){
             dp[i]=(dp[i-1]+dp[i-2])%mod;
         }
         for(int i=0;i<=n;i++){
             result+=dp[i]%mod;
         }

    return result%mod;
    }
};

