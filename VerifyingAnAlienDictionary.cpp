/*
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order.
The order of the alphabet is some permutation of lowercase letters.
Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted
lexicographically in this alien language.

Example 1:
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 3:
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app",
because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
*/

class Solution {
public:
    unordered_map<char, int> mp;

    bool cmp(string a, string b){
        if(a==b)
            return true;
        int i=0;
        while(a[i]==b[i])
            i++;
    return mp[a[i]]<mp[b[i]];
    }

    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<order.size();i++){
            mp[order[i]]=i;
        }
        int i=1;
        while(i<words.size() and cmp(words[i-1], words[i])){
            i++;
        }

    return i<words.size() ? false : true;
    }
};
