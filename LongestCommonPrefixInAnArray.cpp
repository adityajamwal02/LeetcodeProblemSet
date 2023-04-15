/*
Given a array of N strings, find the longest common prefix among all strings present in the array.

Example 1:
Input:
N = 4
arr[] = {geeksforgeeks, geeks, geek,
         geezer}
Output: gee
Explanation: "gee" is the longest common
prefix in all the given strings.

Example 2:
Input:
N = 2
arr[] = {hello, world}
Output: -1
Explanation: There's no common prefix
in the given strings.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonPrefix() which takes the string array arr[] and its size N as inputs and returns the longest common prefix common in all the strings in the array. If there's no prefix common in all the strings, return "-1".


Expected Time Complexity: O(N*max(|arri|)).
Expected Auxiliary Space: O(max(|arri|)) for result.


*/

/// Pure Concept

//User function template for C++

class Solution{
  public:

    string longestCommonPrefix (string arr[], int N)
    {
        if(N==1) return arr[0];
        string result="";
        int j=0;
        for(int i=0;i<N-1;i++){
            if(j<arr[i].size() and j<arr[i+1].size() and arr[i][j]==arr[i+1][j]){
                if(i==0){
                    result+=arr[i][j];
                }
                i--;
                j++;
            }else{
                if(i>0 and result.size()>=j){
                    result.erase(j);
                }
                j=0;
                continue;
            }
        }
    return (result.size()) ? result : "-1";
    }
};

/// Stack based approach

string longestCommonPrefix (string arr[], int N)
    {

        stack<char>st;
        for(int i=arr[0].length()-1;i>=0;i--){
            st.push(arr[0][i]);
        }
        int j=1;
        int c=0,mini=INT_MAX;
        stack<char>temp;
        temp=st;
        while(j<N){
            for(int i=0;i<arr[j].length();i++){
                if(i==arr[0].length())
                break;
                if(temp.top()==arr[j][i]){
                    temp.pop();
                    c++;
                }
                else{
                    mini=min(c,mini);
                    j++;
                    temp=st;
                   c=0;
                    break;
                }
            }

        }
        string ans="";
        for(int i=0;i<mini;i++){
            ans=ans+arr[0][i];
        }
        return  ans;

    }
