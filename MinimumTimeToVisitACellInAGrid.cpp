/*
You are given a m x n matrix grid consisting of non-negative integers where grid[row][col] represents the minimum time required to be able to visit the cell (row, col), which means you can visit the cell (row, col) only when the time you visit it is greater than or equal to grid[row][col].
You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell in the four directions: up, down, left, and right. Each move you make takes 1 second
Return the minimum time required in which you can visit the bottom-right cell of the matrix. If you cannot visit the bottom-right cell, then return -1.

Example 1:
Input: grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
Output: 7
Explanation: One of the paths that we can take is the following:
- at t = 0, we are on the cell (0,0).
- at t = 1, we move to the cell (0,1). It is possible because grid[0][1] <= 1.
- at t = 2, we move to the cell (1,1). It is possible because grid[1][1] <= 2.
- at t = 3, we move to the cell (1,2). It is possible because grid[1][2] <= 3.
- at t = 4, we move to the cell (1,1). It is possible because grid[1][1] <= 4.
- at t = 5, we move to the cell (1,2). It is possible because grid[1][2] <= 5.
- at t = 6, we move to the cell (1,3). It is possible because grid[1][3] <= 6.
- at t = 7, we move to the cell (2,3). It is possible because grid[2][3] <= 7.
The final time is 7. It can be shown that it is the minimum time possible.

Example 2:
Input: grid = [[0,2,4],[3,2,1],[1,0,4]]
Output: -1
Explanation: There is no path from the top left to the bottom-right cell.
*/

class Solution {
    vector<pair<int,int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
public:

    bool check(int x, int y, int n, int m){
        if(x>=0 and x<n and y>=0 and y<m) return true;
    return false;
    }

    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});
        if(grid[1][0]>1 and grid[0][1]>1) return -1;
        while(!st.empty()){
            auto it=*st.begin();
            int px=it.second.first;
            int py=it.second.second;
            int d=it.first;
            st.erase(it);
            for(int i=0;i<4;i++){
                int x=px+moves[i].first;
                int y=py+moves[i].second;
                if(!check(x,y,n,m)) continue;
                if(d+1>=grid[x][y]){
                    if(dp[x][y]>d+1){
                        st.insert({d+1,{x,y}});
                        dp[x][y]=d+1;
                    }
                }else{
                    if(d%2==(grid[x][y])%2){
                      if(dp[x][y]>grid[x][y]+1){
                            st.insert({grid[x][y]+1,{x,y}});
                            dp[x][y]=grid[x][y]+1;
                        }
                    }
                    else if(d%2!=(grid[x][y])%2){
                        if(dp[x][y]>grid[x][y])
                        {
                            st.insert({grid[x][y],{x,y}});
                            dp[x][y]=grid[x][y];
                        }
                    }
                }
            }
        }
        if(dp[n-1][m-1]==INT_MAX){
            return -1;
        }
    return dp[n-1][m-1];
    }
};
