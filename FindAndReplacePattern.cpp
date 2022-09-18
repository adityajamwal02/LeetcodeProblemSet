/*
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

Example 1:
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

Example 2:
Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
*/

class Solution {
public:

    string getPattern(string pattern){
        string ans;
        int j=0;
        map<char, char> mp;
        for(int i=0;i<pattern.size();i++){
            if(mp.find(pattern[i])==mp.end()){
                mp[pattern[i]]='a'+j;
                j++;
            }
        ans.push_back(mp[pattern[i]]);
        }
    return ans;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string pat=getPattern(pattern);
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            string p=getPattern(words[i]);
            if(p==pat){
                ans.push_back(words[i]);
            }
        }
    return ans;
    }
};
