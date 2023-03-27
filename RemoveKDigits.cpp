/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/


class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n<=k) return "0";
        if(k==0) return num;
        stack<char> st;
        string result="";
        st.push(num[0]);
        for(int i=1;i<n;i++){
            while(k>0 and !st.empty() and num[i]<st.top()){
                k--;
                st.pop();
            }
            st.push(num[i]);
            if(st.size()==1 and num[i]=='0'){
                st.pop();
            }
        }
        while(!st.empty() and k){
            k--;
            st.pop();
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
    if(result.size()==0) return "0";
    return result;
    }
};
