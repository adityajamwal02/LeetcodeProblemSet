/*
Given a string s, partition s such that every substring of the partition is a palindrome
Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: s = "a"
Output: 0

Example 3:
Input: s = "ab"
Output: 1
*/

/// Recursive Case

class Solution {
public:

    bool isPalindrome(int i, int j, string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
    return true;
    }

    int helper(int i, string &s, int n){
        if(i==n) return 0;
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost=1+helper(j+1,s,n);
                minCost=min(minCost,cost);
            }
        }
    return minCost;
    }
    int minCut(string s) {
        int n=s.size();
    return helper(0,s,n)-1;
    }
};

/// Memoization

class Solution {
public:

    bool isPalindrome(int i, int j, string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
    return true;
    }

    int helper(int i, string &s, int n, vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost=1+helper(j+1,s,n,dp);
                minCost=min(minCost,cost);
            }
        }
    return dp[i]=minCost;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
    return helper(0,s,n,dp)-1;
    }
};

/// Tabulation

class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
    return true;
    }

    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int minCost=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    minCost=min(minCost,1+dp[j+1]);
                }
            }
        dp[i]=minCost;
        }
    return dp[0]-1;
    }
};
