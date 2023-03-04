/*
You are given two string arrays words1 and words2.
A string b is a subset of string a if every letter in b occurs in a including multiplicity.
For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.
Return an array of all the universal strings in words1. You may return the answer in any order.

Example 1:
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]
*/


class Solution {
public:
    bool check(string word, vector<int> hash){
        for(char ch : word){
            if(hash[ch-'a']!=0){
                hash[ch-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            if(hash[i]>0) return false;
        }
    return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26,0);
        for(string st: words2){
            vector<int> temp(26,0);
            for(auto ch : st){
                temp[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                freq[i]=max(freq[i], temp[i]);
            }
        }
        vector<string> result;
        for(auto i : words1){
            if(check(i,freq)){
                result.push_back(i);
            }
        }
    return result;
    }
};

