/*
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

Example 1:
Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation:
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.

Example 2:
Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.
*/


/// Sliding window + unordered_map

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        unordered_map<char, int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int i=0, j=0, ans=INT_MAX;
        if(mp['a']>=k and mp['b']>=k and mp['c']>=k){
            ans=min(ans,n+i-j);
        }
        while(j<n){
            mp[s[j]]--;
            if(mp['a']>=k and mp['b']>=k and mp['c']>=k){
                ans=min(ans,n-j+i-1);
            }
            while(i<=j and !(mp['a']>=k and mp['b']>=k and mp['c']>=k)){
                mp[s[i]]++;
                i++;
            }
        j++;
        }
        if(ans==INT_MAX) return -1;
    return ans;
    }
};
