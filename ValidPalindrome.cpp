/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

class Solution {
public:

    bool checkPalindrome(string &s1, int i){
        int n=s1.size();
        if(i>=n/2)
            return true;
        if(s1[i]!=s1[n-i-1])
            return false;
    return checkPalindrome(s1, i+1);
    }
    bool isPalindrome(string s) {
        if(s=="")
            return true;
        transform(s.begin(),s.end(),s.begin(), ::tolower);
        string s1="";
        for(auto ch : s){
            if((ch>='a' and ch<='z') or (ch>='0' and ch<='9'))
            s1.push_back(ch);
        }

    return checkPalindrome(s1,0);
    }
};
