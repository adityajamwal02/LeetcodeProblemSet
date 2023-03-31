/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.

Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""
*/

/// PQ + map

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        int maxFreq=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            maxFreq=max(maxFreq,mp[s[i]]);
        }
        if(maxFreq>(n+1)/2) return "";
        priority_queue<pair<int, char>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        string result="";
        pair<int, char> prev={-1,'#'};
        while(!pq.empty()){
            pair<int,char> curr=pq.top();
            pq.pop();
            result+=curr.second;
            curr.first--;
            if(prev.first>0){
                pq.push(prev);
            }
        prev=curr;
        }
    return result;
    }
};
