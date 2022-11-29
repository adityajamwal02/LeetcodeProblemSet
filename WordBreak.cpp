/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/


/// Recursion

class Solution {
public:

    bool helper(int index, string &s, set<string> &dictionary){
        if(index==s.size()) return true;
        for(int i=index;i<s.size();i++){
            string curr=s.substr(index, i-index+1);
            if(dictionary.find(curr)!=dictionary.end() and helper(i+1,s,dictionary)){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dictionary(wordDict.begin(), wordDict.end());
    return helper(0, s, dictionary);
    }
};

/// Memoization

class Solution {
public:

    bool helper(int index, string &s, set<string> &dictionary, vector<int> &dp){
        if(index==s.size()) return true;
        if(dp[index]!=-1){
            return dp[index];
        }

        for(int i=index;i<s.size();i++){
            string curr=s.substr(index, i-index+1);
            if(dictionary.find(curr)!=dictionary.end() and helper(i+1,s,dictionary,dp)){
                return dp[index]=true;
            }
        }
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dictionary(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);

    return helper(0, s, dictionary, dp);
    }
};

/// Tabulation

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dictionary(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[s.size()]=true;
        for(int index=s.size()-1;index>=0;index--){
            for(int i=index;i<s.size();i++){
                string curr=s.substr(index, i-index+1);
                if(dictionary.find(curr)!=dictionary.end() and dp[i+1]){
                    dp[index]=true;
                    break;
                }
            }
        }
    return dp[0];
    }
};

