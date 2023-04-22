/*
You are given an array A of integers of length N. You need to calculate factorial of each number. The answer can be very large, so print it modulo 109 + 7.

Example 1:
Input:
N = 5
A[] = {0, 1, 2, 3, 4}
Output:
1 1 2 6 24
Explanation:
Factorial of 0 is 1,
factorial of 1 is 1, factorial of 2 is 2,
factorial of 3 is 6 and so on.

Example 2:
Input:
N = 3
A[] = {5, 6, 3}
Output:
120 720 6
Explanation:
Factorial of 5 is 120,
factorial of 6 is 720,
factorial of 3 is 6.

Your Task:
Complete the function factorial() which takes list a and single integer n, as input parameters and returns a list of factorials of the numbers in the list a.

Expected Time Complexity: O(max(A) + N)
Expected Auxiliary Space: O(max(A))
*/

//User function template for C++

class Solution{
public:
    int mod=1e9+7;

    vector<long long> factorial(vector<long long> a, int n) {
        vector<long long> result(n);
        vector<long long> dp(1e5+1, 0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=1e5;i++){
            dp[i]=(i*dp[i-1])%mod;
        }
        for(int i=0;i<n;i++){
            result[i]=dp[a[i]];
        }
    return result;
    }
};
