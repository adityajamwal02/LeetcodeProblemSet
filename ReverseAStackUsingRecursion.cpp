/*
You are given a stack St. You have to reverse the stack using recursion.

Example 1:
Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}

Example 2:
Input:
St = {4,3,9,6}
Output:
{6,9,3,4}
Your Task:

You don't need to read input or print anything. Your task is to complete the function Reverse() which takes the stack St as input and returns the reversed stack.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/


//User function Template for C++

class Solution{
public:
    void insert(stack<int> &st, int element){
        if(st.size()==0){
            st.push(element);
            return;
        }
        int temp=st.top();
        st.pop();
        insert(st,element);
        st.push(temp);
    return;
    }
    void Reverse(stack<int> &St){
        if(St.size()==1){
            return;
        }
        int temp=St.top();
        St.pop();
        Reverse(St);
        insert(St, temp);
    return;
    }
};