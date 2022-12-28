/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
Example 1
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        unordered_map<char, int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            int v=it->second;
            ans+=v/2 *2;
            if(ans%2==0 and v%2==1)
                ans++;
        }
    return ans;
    }
};
