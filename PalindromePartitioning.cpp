/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]
*/


class Solution {
public:

    bool isPalindrome(string s, int low, int high){
        while(low<=high){
            if(s[low++]!=s[high--])
                return false;
        }
    return true;
    }

    void helper(int index, string s, vector<string> &path, vector<vector<string>> &ans){
        if(index==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                helper(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(0,s,path,ans);

        return ans;
    }
};
