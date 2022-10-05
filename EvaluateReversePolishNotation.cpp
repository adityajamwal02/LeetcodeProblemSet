/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
Note that division between two integers should truncate toward zero.
It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result,
and there will not be any division by zero operation.

Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/


class Solution {
public:
    long long getAns(long long a, long long b, string i){
        if(i=="+") return a+b;
        if(i=="-") return a-b;
        if(i=="*") return a*b;
        return a/b;
    }

    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==1) return stoi(tokens[0]);

        stack<string> s;
        int curr = 0;
        for(auto i: tokens){
            if(i!="+" && i!="-" && i!="*" && i!="/") s.push(i);
            else{
                long long b = stoi(s.top());
                s.pop();
                long long a = stoi(s.top());
                s.pop();

                curr = getAns(a, b, i);
                s.push(to_string(curr));
            }
        }
        return curr;
    }
};
