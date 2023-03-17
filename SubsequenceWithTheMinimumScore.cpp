/*
You are given two strings s and t.
You are allowed to remove any number of characters from the string t.
The score of the string is 0 if no characters are removed from the string t, otherwise:
Let left be the minimum index among all removed characters.
Let right be the maximum index among all removed characters.
Then the score of the string is right - left + 1.
Return the minimum possible score to make t a subsequence of s.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abacaba", t = "bzaa"
Output: 1
Explanation: In this example, we remove the character "z" at index 1 (0-indexed).
The string t becomes "baa" which is a subsequence of the string "abacaba" and the score is 1 - 1 + 1 = 1.
It can be proven that 1 is the minimum score that we can achieve.

Example 2:
Input: s = "cde", t = "xyz"
Output: 3
Explanation: In this example, we remove characters "x", "y" and "z" at indices 0, 1, and 2 (0-indexed).
The string t becomes "" which is a subsequence of the string "cde" and the score is 2 - 0 + 1 = 3.
It can be proven that 3 is the minimum score that we can achieve.
*/

class Solution {
public:
    int minimumScore(string s, string t) {
        int n=t.size(), res=t.size(), j=0;
        vector<int> left(n,0), right(n,0);
        for(int i=0;i<s.size() and j<left.size();i++){
            if(t[j]==s[i]){
                left[j]=i;
                res=min(res,n-1-(j+1)+1);
                j++;
            }
        }
        while(j < t.size()) {
            left[j] = INT_MAX;
            j++;
        }
        j = t.size() - 1;
        for(int i=s.size()-1;i>=0 && j>=0;i--) {
           if(s[i] == t[j]) {
               right[j] = i;
               res = min(res, j-1+1);
               j--;
            }
        }
        while(j>=0) {
            right[j] = -1;
            j--;
        }
        if(right[0]!=-1 || left[left.size()-1] != INT_MAX) {
            return 0;
        }
        j = 1;
        for(int i =0;i<t.size();i++) {
            if(left[i] == INT_MAX) {
                break;
            }
            int left_index = left[i];
            j = max(j, i+1);
            while(j<right.size() && left_index>=right[j]) {
                j++;
            }
            res = min(res, j-1 - (i+1) + 1);

        }
        return res;
    }
};
