/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:
Input: s = "God Ding"
Output: "doG gniD"
*/

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size(),i=0,k=0;
        while(i<n){
            if(s[i]==' ')
            {
                reverse(s.begin()+k,s.begin()+i);
                k=i+1;
            }
            i++;
        }
        reverse(s.begin()+k,s.begin()+i);
        return s;
    }
};



