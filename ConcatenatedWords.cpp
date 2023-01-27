/*
Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example 1:
Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
"dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

Example 2:
Input: words = ["cat","dog","catdog"]
Output: ["catdog"]
*/


/// Non DP Solution

class Solution {
public:
    map<string, int> mp;
    bool helper(int i, string &s, int count, string q){
        if(i==s.size()){
            if(count>1 and q==""){
                return true;
            }
        return false;
        }
    q+=s[i];
    string g;
        if(mp[q]){
            return (helper(i+1,s,count+1,g) or helper(i+1,s,count,q));
        }
    return helper(i+1,s,count,q);
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        for(auto it : words){
            mp[it]++;
        }
        for(auto it : words){
            string temp=it;
            string q;
            if(helper(0,it,0,q)){
                ans.push_back(it);
            }
        }
    return ans;
    }
};


/// DP solution

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> words_set;
        for (string word : words) words_set.insert(word);
        vector<string> res;

        for (string word : words) {
            int n = word.size();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue;
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n && words_set.count(word.substr(i, j - i))) {
                        dp[j] = 1;
                    }
                }
                if (dp[n]) {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;

    }
};
