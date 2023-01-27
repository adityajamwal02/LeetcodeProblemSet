/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
The following rules define a valid string:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true
*/


/// Stack Solution

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> op,st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                op.push(i);
            }else if(s[i]=='*'){
                st.push(i);
            }else{
                if(!op.empty()){
                    op.pop();
                }else if(!st.empty()){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        while(!op.empty()){
            if(st.empty()){
                return false;
            }else if(op.top() < st.top()){
                op.pop();
                st.pop();
            }else{
                return false;
            }
        }
    return true;
    }
};


/// Recursion try

class Solution {
public:
    bool checkValidString(string s) {
        int lpMin=0,lpMax=0; //using them like stack, left parenthesis range [lpMin,lpMax]

        for(const char &c:s){
            if(c=='('){
               lpMin++;
               lpMax++;
            }else if(c==')'){
                lpMin--;
                lpMax--;
            }else{//only for '*'
                lpMin--;//take ')'
                lpMax++;//take '('
            }
            if(lpMax<0){
                //we can never succeed )()()()((()))
                //we got more ) then ( => result is first char is )
                //=> which cannot make this string valid.
                return false;
            }
            lpMin = max(lpMin, 0);
            //lpMin<0 => we undo line 66 because taking this can never make this valid string..
            //eg *()
            //'if' and 'else if' work as stack for '(' and ')'
            // ((()())) canceld
            //left -> *()
            //now the string can be
            //(() -> take '(' in a hope that we may get success, [0,1]
            //)(), -> it will disappoint us  -> 'X'
            //but you might say lets take it whats the harm
            //we are here to hunt for true,true,true,true,true,true not false
            //lpMin becomes negative becase we cancelled all '(' with ')' and now we got ')'
            //to cancel '(' which we dont have

            //lpMax become min becuase of same reason but but but..
            //it has used actual ')' not from '*' becuase '*' only ++ lpMax only actual ')' --
            //lpMax
            //so if lpMax become neg we can be certain to return false;

            //() -> ignore * -> we might get success [0,0]
        }
        return lpMin==0;
    }
};
