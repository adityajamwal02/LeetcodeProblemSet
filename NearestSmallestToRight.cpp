

/// Nearest smallest to the right of an element


#include<bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> v;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() and st.top()>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            v.push_back(-1);
        }else{
            v.push_back(st.top());
        }
    st.push(arr[i]);
    }
    reverse(v.begin(), v.end());
return v;
}
