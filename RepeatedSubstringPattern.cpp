/*
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:
Input: s = "aba"
Output: false

Example 3:
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        string mix=s+s;
        for(int i=1;i<n;i++)
           {
             string str=mix.substr(i,n);
             if(str==s)
                  return true;
           }
    return false;
    }
};
