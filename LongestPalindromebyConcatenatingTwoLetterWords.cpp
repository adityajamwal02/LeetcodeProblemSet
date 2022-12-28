/*
You are given an array of strings words. Each element of words consists of two lowercase English letters.
Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
A palindrome is a string that reads the same forward and backward.

Example 1:
Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
*/



class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        for(string &word : words){
            count[word]++;
        }
        int ans=0; bool centre=false;
        for(auto &[word,countofWord] : count){
            if(word[0]==word[1]){
                if(countofWord%2==0){
                    ans+=countofWord;
                }
                else{
                    ans+=countofWord-1;
                    centre=true;
                }
            }
            else if(word[0]<word[1] and count.count({word[1],word[0]}))
                ans+=2*min(countofWord, count[{word[1], word[0]}]);
        }
        if(centre){
            ans++;
        }
    return 2*ans;
    }
};
