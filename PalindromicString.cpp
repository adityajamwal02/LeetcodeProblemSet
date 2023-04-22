/*
Given string s and an integer, you have to transform s into a palindrome. In order to achieve that you have to perform exactly k insertion of characters(you cannot perform anymore or less number of insertions). The task is to check if the string can be converted to a palindrome by making exactly k insertions.

Example 1:

Input: s = "abac", K = 2
Output: 1
Explanation: "abac" can be transformed to
"cabbac" (which is palindrome) adding
two characters c and b.
Example 2:
Input: s = "abcde", K = 3
Output: 0
Explanation: "abcde" cannot be transformed
to palindrome using 3 insertions.

Your Task:
You don't need to read input or print anything. Complete the function isPossiblePalindrome() which takes s and K as input parameters and returns a boolean value

Expected Time Complexity: O(|s|2)
Expected Auxiliary Space: O(|s|2)
*/

class Solution{

	public:

	int helper(string &A, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        else if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(A[i]==A[j]){
            return dp[i][j]=2+helper(A,i+1,j-1,dp);
        }
        else{
            return dp[i][j]=max(helper(A,i+1,j,dp),helper(A,i,j-1,dp));
        }
    }

	int isPossiblePalindrome(string s, int K)
	{
	    int n=s.size();
	    vector<vector<int>> dp(n,vector<int>(n,-1));
        int result = helper(s,0,n-1,dp);
    return (n-result<=K);
	}

};
