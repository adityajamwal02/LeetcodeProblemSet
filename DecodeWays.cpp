/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse
of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
Given a string s containing only digits, return the number of ways to decode it.
The test cases are generated so that the answer fits in a 32-bit integer.


Example 1:
Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:
Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
*/

/// Memoization

class Solution {
public:
    int n;

    int help(int index, string &s, vector<int> &dp){
        if(index>n)
            return 0;
        if(index==n)
            return 1;
        if(dp[index]!=-1)
            return dp[index];
        int pick1=0, pick2=0;
        if(s[index]!='0')
            pick1=help(index+1,s,dp);
        if(index+1<n and s[index]!='0'){
            if(s[index]>='3')
                pick2=0;
            else if(s[index]=='2' and s[index+1]>='7')
                pick2=0;
            else
                pick2=help(index+2,s,dp);
        }
    return dp[index]=pick1+pick2;
    }

    int numDecodings(string s) {
        n=s.size();
        vector<int> dp(n,-1);
        return help(0,s,dp);
    }
};


/// Tabulation


class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+2,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            int pick1=0, pick2=0;
            if(s[i]!='0'){
                pick1=dp[i+1];
                string str;
                str+=s[i];
                str+=s[i+1];
                if(stoi(str)<=26) pick2=dp[i+2];
			}
			dp[i]=pick1+pick2;
		}
		return dp[0];
	}
};


/// Space Optimized

int numDecodings(string s) {
		int n=s.size();
		int curr,last1=1,last2=0;
		for(int i=n-1;i>=0;i--){
			int one=0,two=0;
			if(s[i]!='0'){
				one=last1;
				string str;
				str+=s[i];
				str+=s[i+1];
				if(stoi(str)<=26) two=last2;
			}
			curr=one+two;
			last2=last1;
			last1=curr;
		}
		return curr;
	}
};


