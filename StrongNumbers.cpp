/*
Strong Numbers are the numbers whose sum of factorial of digits is equal to the original number. Given a number, the task is to check if it is a Strong Number or not.

Example 1:
Input: 145
Output: 1
Explanation: 1! + 4! + 5! = 145

Example 2:
Input: 5314
Output: 0
Explanation: 5! + 3! + 1! + 4!
is not equal to 5314.

Your Task:
You don't need to read or print anything. Your task is to complete the function is_StrongNumber() which takes the number as input parameter and returns 1 if it is Strong Number otherwise returns 0.

Expected Time Complexity : O(Number of digits in N)
Expected Space Complexity: O(1)
*/

class Solution
{
public:
	public:
	   int mod=1e9+7;

	   void factorial(int num, vector<int> &dp){
	       dp[0]=dp[1]=1;
	       for(int i=2;i<=num;i++){
	           dp[i]=(i*dp[i-1])%mod;
	       }
	   }

		int is_StrongNumber(int n)
		{
		    vector<int> dp(10,0);
		    factorial(9,dp);
		    long long maxTotal=0;
		    int m=n;
		    while(m>0){
		        int curr=m%10;
		        maxTotal+=dp[curr];
		        m/=10;
		    }
		return (maxTotal==n);
		}
};
