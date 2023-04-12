/*
Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​
A string is said to be palindrome if it the same string when reversed.

Example 1:
Input: s = "abcbdd"
Output: true
Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.

Example 2:
Input: s = "bcbddxy"
Output: false
Explanation: s cannot be split into 3 palindromes
*/

/// DP Solution

class Solution {
public:
    int dp[2005][4];

    void fillPalindrome(string s, int n, vector<vector<bool>> &isPalin){
        for(int gap=0;gap<n;gap++){
            for(int i=0;i+gap<n;i++){
                int j=i+gap;
                if(gap==0){
                    isPalin[i][j]=true;
                }else if(gap==1){
                    isPalin[i][j]=(s[i]==s[j]);
                }else{
                    if(s[i]==s[j]){
                        isPalin[i][j]=isPalin[i+1][j-1];
                    }
                }
            }
        }
    }

    bool helper(string &s, int i, int n, int counter, vector<vector<bool>> &isPalin){
        if(i==n and counter==0){
            return true;
        }
        if(counter<0) return false;
        if(dp[i][counter]!=-1) return dp[i][counter];
        for(int j=i;j<n;j++){
            if(isPalin[i][j]){
                if(helper(s,j+1,n,counter-1,isPalin)){
                    return dp[i][counter]=true;
                }
            }
        }
    return dp[i][counter]=false;
    }

    bool checkPartitioning(string s){
        int n=s.size();
        vector<vector<bool>> isPalin(n,vector<bool> (n,false));
        fillPalindrome(s,n,isPalin);
        memset(dp,-1,sizeof(dp));

    return helper(s,0,n,3,isPalin);
    }
};
