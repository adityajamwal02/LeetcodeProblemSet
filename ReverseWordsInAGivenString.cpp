/*
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr

Your Task:
You dont need to read input or print anything. Complete the function reverseWords() which takes string S as input parameter and returns a string containing the words in reversed order. Each word in the returning string should also be separated by '.'
*/

/// Stack Solution

        stack<string> st;
        string result = "";
        string p = "";
        for(int i=0;i<S.size();i++){
            if(S[i]=='.'){
                p+='.';
                st.push(p);
                p = "";
                continue;
            }
            else{
                p+=S[i];
            }
        }
        p+='.';
        st.push(p);
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        result.pop_back();
        return result;



/// String Solution


string reverseWords(string S)
    {
        // code here
        string s="";
        vector<string>v;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='.')
            {
                v.push_back(s);
                s="";
                continue;
            }
            s+=S[i];
        }
        v.push_back(s);
        string str="";
        for(int i=v.size()-1;i>=0;i--)
        {
            if(i!=0){
            str+=v[i];
            str+='.';
            }
            else
            {
                str+=v[i];
            }
        }
        return str;
    }

