/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
*/

/// Stack

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        for(int i=0;i<s.size();i++){
            if(!s1.empty() and s[i]=='#'){
                s1.pop();
            }else if(s[i]!='#'){
                s1.push(s[i]);
            }
        }
        for(int i=0;i<t.size();i++){
            if(!s2.empty() and t[i]=='#'){
                s2.pop();
            }else if(t[i]!='#'){
                s2.push(t[i]);
            }
        }
        if(s1==s2){
            return true;
        }
        return false;
    }
};
