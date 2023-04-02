/*
You are given a binary string s consisting only of zeroes and ones.
A substring of s is considered balanced if all zeroes are before ones and the number of zeroes is equal to the number of ones inside the substring. Notice that the empty substring is considered a balanced substring.
Return the length of the longest balanced substring of s.
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: s = "01000111"
Output: 6
Explanation: The longest balanced substring is "000111", which has length 6.

Example 2:
Input: s = "00111"
Output: 4
Explanation: The longest balanced substring is "0011", which has length 4.

Example 3:
Input: s = "111"
Output: 0
Explanation: There is no balanced substring except the empty substring, so the answer is 0.
*/

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n=s.size(), ans=0, index=0;
        for(int i=0;i<n;i++){
            int zero=0;
            index=i;
            while(s[index]=='0' and index<n){
                zero++;
                index++;
            }
            int one=0;
            while(s[index]=='1' and index<n){
                one++;
                index++;
            }
            ans=max(ans,min(one,zero));
            i=index-1;
        }
    return ans*2;
    }
};
