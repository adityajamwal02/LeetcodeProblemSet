/*
Given a string s, return true if s is a good string, or false otherwise.
A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Example 1:
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
*/


class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        unordered_set<int> count;
        for(auto [a, b]: mp){
            count.insert(b);
            if(count.size()>1)
                return false;
        }
    return true;
    }
};
