/*
We have a string s of length n, which contains only UPPERCASE characters and we have a number k (always less than n). We can make at most k changes in our string. In one change, you can replace any s[i] (0<= i < n) with any uppercase character (from 'A' to 'Z'). After k changes, find the maximum possible length of the sub-string which have all same characters.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Change 2 'B' into 'A'.
Now s = "AAAA"

Example:
Input: s = "ADBD", k = 1
Output: 3
Explanation: Change 'B' into 'D'.
Now s = "ADDD"

Your Task:
You don't need to read or print anything. Your task is to complete the function characterReplacement() which takes s and k as input parameters and returns the maximum length of sub-string after doing k changes.

Expected Time Complexity: O(n)
Expected Space Complexity: O(26)
*/

/// Sliding Window

class Solution {
	public:
	    int solve(string &s, char c, int k){
	        int res=0, i=0, replace=0;
	        for(int j=0;j<s.size();j++){
	            if(s[j]!=c){
	                replace++;
	            }
	            while(replace>k){
	                if(s[i]!=c){
	                    replace--;
	                }
	                i++;
	            }
	            res=max(res,j-i+1);
	        }
	       return res;
	    }
		int characterReplacement(string s, int k){
		    int maxLen=0;
		    for(char c='A';c<='Z';c++){
		        maxLen=max(maxLen,solve(s,c, k));
		    }
		return maxLen;
		}

};
