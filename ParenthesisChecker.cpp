/*
Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).
Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

Example 1:
Input:
{([])}
Output:
true
Explanation:
{ ( [ ] ) }. Same colored brackets can form
balanced pairs, with 0 number of
unbalanced bracket.

Example 2:
Input:
()
Output:
true
Explanation:
(). Same bracket can form balanced pairs,
and here only 1 type of bracket is
present and in balanced way.

Example 3:
Input:
([]
Output:
false
Explanation:
([]. Here square bracket is balanced but
the small bracket is not balanced and
Hence , the output will be unbalanced.
Your Task:
This is a function problem. You only need to complete the function ispar() that takes a string as a parameter and returns a boolean value true if brackets are balanced else returns false. The printing is done automatically by the driver code.
*/


class Solution
{
    public:

    bool match(char top, char ch){
        if(top=='(' and ch==')' or top=='[' and ch==']' or top=='{' and ch=='}') return true;

    return false;
    }

    bool ispar(string x)
    {
        stack<char> st;
        for(int i=0;i<x.size();i++){
            char ch = x[i];
            if(ch=='(' or ch=='[' or ch=='{'){
                st.push(ch);
            }else{
                if(!st.empty()){
                    char temp=st.top();
                    if(match(temp,ch)) st.pop();
                    else return false;
                }else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
    return false;
    }

};
