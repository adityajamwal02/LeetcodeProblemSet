/*
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
*/

class Solution {
public:
    int check(string &s, int l, int r){
        while(l>=0 and r<s.size() and s[l]==s[r]){
            l--;
            r++;
        }
    return r-l-1;
    }
    string longestPalindrome(string s) {
        int ans=0, st=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int len1=check(s,i,i);
            int len2=check(s,i,i+1);
            int len=max(len1,len2);
            if(len>ans){
                ans=len;
                st=i-(len-1)/2;
            }
        }
    return s.substr(st,ans);
    }
};

