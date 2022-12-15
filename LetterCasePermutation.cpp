/*
Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create. Return the output in any order.

Example 1:
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: s = "3z4"
Output: ["3z4","3Z4"]
*/


class Solution {
public:
    void permuteRecursive(string s, vector<string> &res, int i){
        if(i>=s.size()){
            res.push_back(s);
            return;
        }
        permuteRecursive(s,res,i+1);
        if(isupper(s[i])){
            s[i]=tolower(s[i]);
            permuteRecursive(s,res,i+1);
        }
        else if(islower(s[i])){
            s[i]=toupper(s[i]);
            permuteRecursive(s,res,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        permuteRecursive(s,result,0);
        return result;
    }
};

