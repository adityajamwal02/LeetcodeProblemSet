/*
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10
*/

class Solution {
public:
    void helper(string s, int index, int dot, string temp, vector<string> &result){
        if(dot>4) return;
        if(index==s.size()){
            if(dot==4){
                result.push_back(temp.substr(0,temp.size()-1));
            }
        return;
        }
        for(int i=index;i<min(index+3,(int)s.size());i++){
            if(stoi(s.substr(index,i-index+1))<256 and (index==i or s[index]!='0')){
                helper(s,i+1,dot+1,temp+s.substr(index,i-index+1)+".",result);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n=s.size();
        helper(s,0,0,"",result);
    return result;
    }
};
