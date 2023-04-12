/*
You are given a string s containing lowercase letters and an integer k. You need to :
First, change some characters of s to other lowercase English letters.
Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.
Return the minimal number of characters that you need to change to divide the string.

Example 1:
Input: s = "abc", k = 2
Output: 1
Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.

Example 2:
Input: s = "aabbc", k = 3
Output: 0
Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.

Example 3:
Input: s = "leetcode", k = 8
Output: 0

Constraints:
1 <= k <= s.length <= 100.
s only contains lowercase English letters.
*/

/// Recursion

class Solution {
public:
    int partioning(string s, int i, int cuts, int n, vector<vector<int>> &dp){
        if(cuts==0) return dp[i][n-1];
        int minValue=INT_MAX;
        for(int j=i;j<n-cuts;j++){
            minValue=min(minValue,dp[i][j]+partioning(s,j+1,cuts-1,n,dp));
        }
    return minValue;
    }

    int palindromePartition(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int k=0;k<n;k++){
            for(int i=0, j=k;j<n;i++,j++){
                if(s[i]==s[j]){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=1;
                }

                if(k>1){
                    dp[i][j]+=dp[i+1][j-1];
                }
            }
        }
    return partioning(s,0,k-1,n,dp);
    }
};

/// Memoization

class Solution {
public:
    int numberOfChangesRequired(int i, int j, string &s){
        int counter=0;
        while(i<j){
            if(s[i]!=s[j]){
                counter++;
            }
            i++;
            j--;
        }
    return counter;
    }
    int helper(int i, int n, string &s, int k, vector<vector<int>> &dp){
        if(k==1){
            return numberOfChangesRequired(i,n-1,s);
        }

        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int minValue=INT_MAX;
        for(int j=i;j<=n-k;j++){
            int counter=numberOfChangesRequired(i,j,s)+helper(j+1,n,s,k-1,dp);
            minValue=min(minValue,counter);
        }
    return dp[i][k]=minValue;
    }

    int palindromePartition(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));

    return helper(0,n,s,k,dp);
    }
};
