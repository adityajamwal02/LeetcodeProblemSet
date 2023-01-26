/*
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

Example 1:
Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2

Example 2:
Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
*/


class Solution {
public:
    int operate(int x, int y, char oper){
        if(oper=='+') return x+y;
        if(oper=='-') return x-y;
        if(oper=='*') return x*y;
    return 0;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        bool isNum=true;
        for(int i=0;i<expression.size();i++){
            if(!isdigit(expression[i])){
                isNum=false;
                vector<int> left=diffWaysToCompute(expression.substr(0,i));
                vector<int> right=diffWaysToCompute(expression.substr(i+1, expression.size()));
                for(int x: left){
                    for(int y: right){
                        ans.push_back(operate(x,y,expression[i]));
                    }
                }
            }
        }
    if(isNum) ans.push_back(stoi(expression));
    return ans;
    }
};
