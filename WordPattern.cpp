/*
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
*/

/// Bijection Approach

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mp;
        map<string, char> ms;
        int j=0;
        for(int i=0;i<pattern.size();i++){
            string temp="";
            while(j<s.size() and s[j]!=' ')
                temp+=s[j++];
            j++;
            if(temp.empty() or (mp.find(pattern[i])!=mp.end() or ms.find(temp)!=ms.end()) and (mp[pattern[i]]!=temp or ms[temp]!=pattern[i]))
                return false;
            mp[pattern[i]]=temp;
            ms[temp]=pattern[i];
            temp="";
        }
        if(j-1<s.size())
            return false;

    return true;
    }
};
