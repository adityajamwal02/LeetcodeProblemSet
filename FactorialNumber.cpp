/*
For a given number N, find whether it is a factorial number or not. A Factorial number is a number which is equal to the factorial value of other numbers.

Example 1:
Input:
N = 6
Output:
1
Explanation:
6 is factorial of 3

Example 2:
Input:
N = 5
Output:
0
Explanation:
no number's factorial is 5.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isFactorial() which takes an integer N as input parameters and returns 1 if N is a factorial number, or 0 otherwise.


Expected Time Complexity: O(log N)
Expected Space Complexity: O(1)

*/

class Solution{
public:
    int isFactorial(int N){
        vector<int> dp(10,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=9;i++){
            dp[i]=(i*dp[i-1]);
        }
        int result=binary_search(dp.begin(), dp.end(), N);
    return result;
    }
};
