/*
Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts.
For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.
Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.

Example 1:
Input: pizza = ["A..","AAA","..."], k = 3
Output: 3
Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.

Example 2:
Input: pizza = ["A..","AA.","..."], k = 3
Output: 1

Example 3:
Input: pizza = ["A..","A..","..."], k = 1
Output: 1
*/

class Solution {
public:
    int mod=1000000007;
    long long solve(vector<string> &pizza, int k, int i, int j, vector<vector<vector<int>>> &dp, int n, int m){
        if(k==0){
            for(int r=i;r<n;r++){
                for(int c=j;c<m;c++){
                    if(pizza[r][c]=='A') return 1;
                }
            }
        return 0;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        long long ans=0;
        int flag=0;
        for(int r=i;r<n;r++){
            if(flag==0){
                for(int c=j;c<m;c++){
                    if(pizza[r][c]=='A'){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1){
                ans+=solve(pizza,k-1,r+1,j,dp,n,m);
            }
        }
        flag=0;
        for(int c=j;c<m;c++){
            if(flag==0){
                for(int r=i;r<n;r++){
                    if(pizza[r][c]=='A'){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1){
                ans+=solve(pizza,k-1,i,c+1,dp,n,m);
            }
        }
    return dp[i][j][k]=ans%mod;
    }

    int ways(vector<string>& pizza, int k) {
        int n=pizza.size();
        int m=pizza[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k,-1)));

    return solve(pizza,k-1,0,0,dp,n,m);
    }
};
