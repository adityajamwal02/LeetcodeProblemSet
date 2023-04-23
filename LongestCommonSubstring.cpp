/*
Given two strings. The task is to find the length of the longest common substring.

Example 1:
Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.

Example 2:
Input: S1 = "ABC", S2 "ACB", n = 3, m = 3
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonSubstr() which takes the string S1, string S2 and their length n and m as inputs and returns the length of the longest common substring in S1 and S2.

Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).
*/


/// Recursion

class Solution{
    public:
    int result=0;
    int helper(int i, int j, int n, int m, string &s, string &t){
        if(i>=n or j>=m) return 0;
        int ans=0;
        if(s[i]==t[j]){
            ans=1+helper(i+1,j+1,n,m,s,t);
        }
        int t1=helper(i+1,j,n,m,s,t);
        int t2=helper(i,j+1,n,m,s,t);

        result=max(result,ans);

    return ans;
    }

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int res=helper(0,0,n,m,S1,S2);
    return result;
    }
};

/// Memoization


class Solution{
    public:
    int result=0;
    int helper(int i, int j, int n, int m, string &s, string &t,vector<vector<int>> &dp){
        if(i>=n or j>=m) return 0;
        int ans=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            ans=1+helper(i+1,j+1,n,m,s,t,dp);
        }
        int t1=helper(i+1,j,n,m,s,t,dp);
        int t2=helper(i,j+1,n,m,s,t,dp);

        result=max(result,ans);

    return dp[i][j]=ans;
    }

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n,vector<int>(m,-1));

        int res=helper(0,0,n,m,S1,S2,dp);

    return result;
    }
};


/// Tabulation

int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int arr[n][m];
        int maxm=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s1[i]==s2[j]){
                    if(i-1>=0&&j-1>=0){
                        arr[i][j]=1+arr[i-1][j-1];
                        maxm=max(maxm,arr[i][j]);
                    }
                    else{
                        arr[i][j]=1;
                         maxm=max(maxm,arr[i][j]);
                    }
                }
                else{
                        arr[i][j]=0;
                }
            }
        }
        return maxm;
    }


/// General Approach

    int count=0;
    int i=0;
    int j=0;
    string temp;
    int ans=0;

    while(i<m && j<m)
    {
        temp+=S2[j];
        if(S1.find(temp)!= string::npos)
        {
            count++;
            ans=max(count,ans);
            j++;
        }
        else
        {
            count=0;
            i++;
            j=i;
            temp="";
        }

    }
    return ans;

