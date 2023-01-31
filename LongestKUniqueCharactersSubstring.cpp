/*
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

Example 1:
Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest
substring with K distinct characters.

Example 2:
Input:
S = "aaaa", K = 2
Output: -1
Explanation: There's no substring with K
distinct characters.
*/

/// Set Solution

int getLengthofLongestSubstring(string s, int k) {
       set<char> tmp{};
    int fs{},large{};

    for(int i=0; i<s.size(); i++){
        tmp.clear();    fs=i;

        if(large>s.size()-i+1)
            break;

        while ((fs<s.size()) && (tmp.size()<k+1)){
            tmp.insert(s[fs]);
            fs++;
        }
        if(((fs-i)>large) && (tmp.size()==k+1))
            large=fs-i-1;
        else if((fs-i)>large)
            large=fs-i;
    }
    return large;
}
