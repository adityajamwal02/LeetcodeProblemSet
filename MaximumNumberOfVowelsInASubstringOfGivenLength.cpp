/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3:
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
*/

/// Sliding Window Approach + Without set

class Solution {
public:

    bool check(char ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u'){
            return true;
        }
    return false;
    }

    int maxVowels(string s, int k) {
        int n=s.size();
        int maxLen=0, curr=0;
        for(int i=0;i<k;i++){
            if(check(s[i])) curr++;
        }
        maxLen=curr;
        int i=0, j=k;
        while(j<n){
            if(check(s[j])) curr++;
            if(check(s[i])) curr--;
            maxLen=max(maxLen,curr);
            j++; i++;
        }
    return maxLen;
    }
};

///  Set Approach + Sliding Window

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int max_count = 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i >= k && vowels.count(s[i-k])) {
                count--;
            }
            if (vowels.count(s[i])) {
                count++;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};
