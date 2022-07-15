class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
                continue;
            }
            if(s[i]==')' and st.top()=='(')
            {
                st.pop();
            }
            else if(s[i]=='}' and st.top()=='{')
            {
                st.pop();
            }
            else if(s[i]==']' and st.top()=='[')
            {
                st.pop();
            }
            else
                st.push(s[i]);
        }
        bool ans;
        if(st.empty())
            ans=true;
        else
            ans=false;

        return ans;
    }
};

