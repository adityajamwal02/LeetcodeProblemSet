/*
You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.



Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.
Example 2:

Input: s = "", t = "y"
Output: "y"
*/


class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch='\0';
        for(auto &c: s)
            ch^=c;
        for (auto &c: t)
            ch^=c;

    return ch;
    }
};
