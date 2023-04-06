/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
Return the number of closed islands.

Example 1:
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation:
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:
Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
*/

class Solution {
public:

    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or vis[i][j]==1 or grid[i][j]==1)
            return;
        vis[i][j]=1;
        dfs(i-1,j,vis,grid);
        dfs(i,j+1,vis,grid);
        dfs(i+1,j,vis,grid);
        dfs(i,j-1,vis,grid);
    }


    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] and grid[i][0]==0){
                dfs(i,0,vis,grid);
            }
            if(!vis[i][m-1] and grid[i][m-1]==0){
                dfs(i,m-1,vis,grid);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] and grid[0][j]==0){
                dfs(0,j,vis,grid);
            }
            if(!vis[n-1][j] and grid[n-1][j]==0){
                dfs(n-1,j,vis,grid);
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==0){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
    return count;
    }
};
