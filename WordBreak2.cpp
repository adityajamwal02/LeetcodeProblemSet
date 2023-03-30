/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

Example 2:
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
*/

class Solution {
public:
    unordered_map<string, vector<string>> mp;

    vector<string> solve(string s, int n, unordered_set<string> &st){
        vector<string> result;

        if(mp.find(s)!=mp.end()) return mp[s];
        if(s.empty()) return result;
        if(st.find(s)!=st.end()){
            result.push_back(s);
        }

        for(int i=0;i<s.size();i++){
            string prefix=s.substr(0,i+1);
            if(st.find(prefix)!=st.end()){
                string suffix=s.substr(i+1);
                vector<string> res = solve(suffix,n,st);
                mp[suffix]=res;
                for(auto str : res){
                    result.push_back(prefix + ' ' + str);
                }
            }
        }
    return result;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        return solve(s,n,st);
    }
};
