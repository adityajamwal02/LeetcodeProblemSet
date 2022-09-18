/*
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.


Example 1:

Input: s = "Hello"
Output: "hello"
*/

class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++)
        {
            s[i]=tolower(s[i]);
        }
        return s;
    }
};
