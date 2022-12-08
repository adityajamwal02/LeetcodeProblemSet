/*
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Example 1:
Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

Example 2:
Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

Example 3:
Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
*/



class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s==goal and set<char>(s.begin(), s.end()).size()<s.size()) return true;
        if(s.size()!=goal.size()) return false;
        vector<int> index;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                index.push_back(i);
            }
        }
        if(index.size()!=2){
            return false;
        }
        swap(s[index[0]],s[index[1]]);
    return s==goal;
    }
};
