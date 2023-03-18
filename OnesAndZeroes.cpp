/*
You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.

Example 1:
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

Example 2:
Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
*/

/// Recursive Solution

class Solution {
public:
    int solve(vector<vector<int>> &input, int sz, int m, int n){
        if(sz==0 or (m==0 and n==0)){
            return 0;
        }
        if(input[0][sz-1]<=m and input[1][sz-1]<=n){
            return max(1+solve(input,sz-1,m-input[0][sz-1],n-input[1][sz-1]), solve(input,sz-1,m,n));
        }
    return solve(input,sz-1,m,n);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        vector<vector<int>> input(2,vector<int> (sz));
        for(int i=0;i<sz;i++){
            string s=strs[i];
            int zero=0, one=0;
            for(int j=0;j<s.size();j++){
                if(s[j]=='0'){
                    zero++;
                }else{
                    one++;
                }
            }
            input[0][i]=zero;
            input[1][i]=one;
        }
    return solve(input,sz,m,n);
    }
};

/// Memoization

class Solution {
public:
    int solve(vector<vector<int>> &input, int sz, int m, int n, vector<vector<vector<int>>> &dp){
        if(sz==0 or (m==0 and n==0)){
            return 0;
        }
        if(dp[sz][m][n]!=-1) return dp[sz][m][n];
        if(input[0][sz-1]<=m and input[1][sz-1]<=n){
            return dp[sz][m][n]=max(1+solve(input,sz-1,m-input[0][sz-1],n-input[1][sz-1],dp), solve(input,sz-1,m,n,dp));
        }
    return dp[sz][m][n]=solve(input,sz-1,m,n,dp);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        vector<vector<int>> input(2,vector<int> (sz));
        vector<vector<vector<int>>> dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(int i=0;i<sz;i++){
            string s=strs[i];
            int zero=0, one=0;
            for(int j=0;j<s.size();j++){
                if(s[j]=='0'){
                    zero++;
                }else{
                    one++;
                }
            }
            input[0][i]=zero;
            input[1][i]=one;
        }
    return solve(input,sz,m,n,dp);
    }
};

/// Tabulation

class Solution {
public:
    int findMaxForm(vector<string>& str, int m, int n) {
        vector<vector<int>> v(2,vector<int> (str.size()));
        vector<vector<vector<int>>> dp(str.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(int i=0;i<str.size();i++){
            string s=str[i];
            int z=0,o=0;
            for(int j=0;j<s.length();j++){
                if(s[j]=='0') ++z;
                else ++o;
            }
            v[0][i]=z;
            v[1][i]=o;
        }
        for(int i=0;i<str.size()+1;i++){
            for(int j=0;j<m+1;j++){
                for(int k=0;k<n+1;k++){
                    if(i==0 || (j==0 && k==0)) dp[i][j][k]=0;
                    else{
                        if(v[0][i-1]<=j && v[1][i-1]<=k) dp[i][j][k]=max(1+dp[i-1][j-v[0][i-1]][k-v[1][i-1]],dp[i-1][j][k]);
                        else dp[i][j][k]=dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[str.size()][m][n];
    }
};
