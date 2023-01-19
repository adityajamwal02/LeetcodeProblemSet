/*
A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
Return the minimum number of flips to make s monotone increasing.

Example 1:
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.

Example 2:
Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.

Example 3:
Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
*/

/// Simple

class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int zeroToOne=0, oneCount=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') zeroToOne++;
            else oneCount++;
            if(zeroToOne>oneCount){
                zeroToOne=oneCount;
            }
        }
    return zeroToOne;
    }
};

/// Top-Down Recursion

  int helperDP(string &s,int i, char prev,vector<vector<int>> &dp)
    {
        if(i>=s.length())return 0;

        if(dp[i][prev-'0']!=-1)return dp[i][prev-'0'];
        int x=INT_MAX,y=INT_MAX;
        if(prev=='0')
        {
            if(s[i]=='0')
            {
                x=helperDP(s,i+1,'0',dp);
                y=helperDP(s,i+1,'1',dp)+1;
            }
            else
            {
                x=helperDP(s,i+1,'1',dp);
                y=helperDP(s,i+1,'0',dp)+1;
            }
        }
        else
        {
            if(s[i]=='0')
            {
                x=helperDP(s,i+1,'1',dp)+1;
            }
            else
            {
                x=helperDP(s,i+1,'1',dp);
            }
        }
        return dp[i][prev-'0']=min(x,y);
    }
