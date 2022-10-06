/*
Given a string s which represents an expression, evaluate this expression and return its value.
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "3+2*2"
Output: 7

Example 2:
Input: s = " 3/2 "
Output: 1

Example 3:
Input: s = " 3+5 / 2 "
Output: 5
*/

class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        if(n==0)
            return 0;
        stack<int> st;
        int currNum=0; char oper='+';
        for(int i=0;i<n;i++){
            char curr=s[i];
            if(isdigit(curr)){
                currNum=(currNum*10)+(curr-'0');
            }
            if(!isdigit(curr) and !iswspace(curr) or i==n-1){
                if(oper=='-')
                    st.push(-currNum);
                else if(oper=='+')
                    st.push(currNum);
                else if(oper=='*'){
                    int top=st.top();
                    st.pop();
                    st.push(top*currNum);
                }
                else if(oper=='/'){
                    int top=st.top();
                    st.pop();
                    st.push(top/currNum);
                }
                oper=curr;
                currNum=0;
            }
        }
        int result=0;
        while(st.size()!=0){
            result+=st.top();
            st.pop();
        }
    return result;
    }
};
