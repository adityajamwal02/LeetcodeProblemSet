/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(), m=b.size();
        int i=0,carry=0;
        string result="";
        while(n>i or m>i or carry!=0){
            int x=0;
            if(i<n and a[n-i-1]=='1')
                x=1;
            int y=0;
            if(i<m and b[m-i-1]=='1')
                y=1;
            result=to_string((x+y+carry)%2)+result;
            carry=(x+y+carry)/2;
            i+=1;
        }
    return result;
    }
};
