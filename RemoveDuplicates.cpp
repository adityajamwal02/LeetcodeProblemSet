/*
Given a string without spaces, the task is to remove duplicates from it.

Note: The original order of characters must be kept the same.

Example 1:

Input: S = "zvvo"
Output: "zvo"
Explanation: Only keep the first
occurrence
Example 2:

Input: S = "gfg"
Output: gf
Explanation: Only keep the first
occurrence
Your task:
Your task is to complete the function removeDups() which takes a single string as input and returns the string. You need not take any input or print anything.


Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(constant)
*/


/// Set Approach

//User function template for C++
class Solution{
public:

	string removeDups(string S)
	{
	   string result="";
	   unordered_set<char> st;
	   for(int i=0;i<S.size();i++){
	       if(st.find(S[i])==st.end()){
	           st.insert(S[i]);
	           result+=S[i];
	       }else{
	           continue;
	       }
	   }
	   return result;
	 }
};
