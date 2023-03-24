/*
You are given two strings s and t. Now your task is to print all longest common sub-sequences in lexicographical order.

Example 1:
Input: s = abaaa, t = baabaca
Output: aaaa abaa baaa

Example 2:
Input: s = aaa, t = a
Output: a
Your Task:
You do not need to read or print anything. Your task is to complete the function all_longest_common_subsequences() which takes string a and b as first and second parameter respectively and returns a list of strings which contains all possible longest common subsequences in lexicographical order.

Expected Time Complexity: O(n4)
Expected Space Complexity: O(K * n) where K is a constant less than n.
*/

/// Aditya Verma Approach

/*
1. find length of LCS (Using DP)
2. Find the all possibles LCS (Using Set + Backtracking)
3. Sort all LCS, and return it.
*/


class Solution
{
	public:
	    set<string> st;

	    void helper(string s, string t, int i, int j, string &temp, vector<string> &result, int count){
	        if(count==0){
	            if(st.find(temp)==st.end()){
	                st.insert(temp);
	                result.push_back(temp);
	            }
	            return;
	        }
	        if(i>=s.size() or j>=t.size()) return;
	        for(int row=i;row<s.size();row++){
	            for(int col=j;col<t.size();col++){
	                if(s[row]==t[col]){
	                    temp.push_back(s[row]);
	                    helper(s,t,row+1,col+1,temp,result,count-1);
	                    temp.pop_back();
	                }
	            }
	        }

	    }

		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    int n=s.size(), m=t.size();
		    int dp[n+1][m+1];
		    for(int i=0;i<n+1;i++){
		        for(int j=0;j<m+1;j++){
		            if(i==0 or j==0){
		                dp[i][j]=0;
		            }
		        }
		    }
		    for(int i=1;i<n+1;i++){
		        for(int j=1;j<m+1;j++){
		            if(s[i-1]==t[j-1]){
		                dp[i][j]=1+dp[i-1][j-1];
		            }else{
		                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		            }
		        }
		    }
		   int length=dp[n][m];
		   vector<string> result;
		   string temp="";
		   helper(s,t,0,0,temp,result,length);
		   sort(result.begin(), result.end());

		return result;
		}
};
