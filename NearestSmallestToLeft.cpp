
/// Nearest smallest to the left of an element


vector<int> Smallestonleft(int arr[], int n)
{
    vector<int> v;
    stack<int> st;
    for(int i=0;i<n;i++){
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
    return v;
}
