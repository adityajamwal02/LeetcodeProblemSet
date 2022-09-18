/*
You are given two strings s1 and s2 of equal length.
A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

Example 1:
Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".

Example 2:
Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap
*/


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)
            return true;
        if(s1.size()!=s2.size())
            return false;
        for(int i=0;i<s1.size()-1;i++){
            for(int j=i+1;j<s1.size();j++){
                swap(s1[i], s1[j]);
                if(s1==s2)
                    return true;
                else
                    swap(s1[j], s1[i]);
            }
        }

    return false;
    }
};
