/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).


Example 1:

Input:
S = "aaaabbaa"
Output:
aabbaa
Explanation:
The longest palindrome string present in
the given string is "aabbaa".

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalindrome() which takes string S as input parameters and returns longest pallindrome present in string.


Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(1)
*/

/// Bool 2D DP used + Sort if collision occurs case

class Solution{
public:
    string longestPalindrome(string S){
        string result=S.substr(0,1);
        int j;
        int n=S.size();
        bool dp[n][n];
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){
                    dp[i][j]=true;
                }else if(gap==1){
                    if(S[i]==S[j]){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=false;
                    }
                }else{
                    if(S[i]==S[j] and dp[i+1][j-1]){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=false;
                    }
                }

                if(dp[i][j] and (j-i+1)>result.size()){
                    result=S.substr(i,j-i+1);
                }
            }
        }
    return result;
    }
};
