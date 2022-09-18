/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
*/


class Solution {
public:
    void combination(string digits, string vec[], string res, int index, vector<string> &ans){
        if(index>=digits.length()){
            ans.push_back(res);
            return;
        }
        int num=digits[index]-'0';
        string value=vec[num];
        for(int i=0;i<value.length();i++){
            res.push_back(value[i]);
            combination(digits, vec, res, index+1, ans);
            res.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        string vec[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string res="";
        int index=0;
        combination(digits, vec, res, index, ans);
        return ans;
    }
};
