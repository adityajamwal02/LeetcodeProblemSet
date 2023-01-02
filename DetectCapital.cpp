/*
We define the usage of capitals in a word to be right when one of the following cases holds:
All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:
Input: word = "USA"
Output: true
Example 2:
Input: word = "FlaG"
Output: false
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int small=0, capital=0;
        for(int i=0;i<n;i++){
            if(word[i]>='A' and word[i]<='Z'){
                capital++;
            }
            if(word[i]>='a' and word[i]<='z'){
                small++;
            }
        }
        if(capital==n or small==n or (isupper(word[0]) and capital==1 and small==n-1)){
            return true;
        }
    return false;
    }
};
