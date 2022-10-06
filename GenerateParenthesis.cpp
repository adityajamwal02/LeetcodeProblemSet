/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/


class Solution {
public:
    vector<string> result;

    void helper(int n, int open, string s){
        if(n==0 and open==0)
            result.push_back(s);
        if(n>0)
            helper(n-1,open+1,s+"(");
        if(open>0)
            helper(n,open-1,s+")");
    }

    vector<string> generateParenthesis(int n) {
        helper(n, 0, "");
    return result;
    }
};
