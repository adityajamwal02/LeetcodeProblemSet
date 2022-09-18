/*
You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
Return the string formed after mapping.

The test cases are generated so that a unique mapping will always exist.

Example 1:
Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

Example 2:
Input: s = "1326#"
Output: "acz"
*/

class Solution {
public:
    string freqAlphabets(string s) {
        int n=s.size();
        int i=0;
        string ans;
        while(i<n){
            int num;
            if(i+1<n and i+2<n and s[i+2]=='#'){
                num=stoi(s.substr(i,2));
                num+=96;
                ans+=(char)num;
                i=i+3;
            }else{
                num=stoi(s.substr(i,1));
                num+=96;
                ans+=(char)num;
                i++;
            }
        }
    return ans;
    }
};
