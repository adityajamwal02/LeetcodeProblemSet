/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "1 + 1"
Output: 2

Example 2:
Input: s = " 2-1 + 2 "
Output: 3

Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
*/


class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        int i=0,ans=0,num=0,sign=1;
        stack<int> st;
        while(i<n){
            if(isdigit(s[i])){
                string temp;
                while(s[i]>='0' and s[i]<='9'){
                    temp+=s[i];
                    i++;
                }
                i--;
                num=stoi(temp);
                num=num*sign;
                ans+=num;
            }
            else if(s[i]=='-'){
                sign=-1;
            }
            else if(s[i]=='+'){
                sign=1;
            }
            else if(s[i]=='('){
                st.push(ans);
                st.push(sign);
                ans=0;
                sign=1;
            }
            else if(s[i]==')'){
                ans*=st.top();
                st.pop();
                ans+=st.top();
                st.pop();
            }
        i++;
        }
    return ans;
    }

};
