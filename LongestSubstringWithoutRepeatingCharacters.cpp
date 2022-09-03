/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0, right=0, len=0;
        vector<int> mp(256, -1);

        while(right<n){
            if(mp[s[right]]!=-1)
                left=max(mp[s[right]]+1, left);

            mp[s[right]]=right;
            len=max(len, right-left+1);
            right++;
        }
        return len;
    }
};
