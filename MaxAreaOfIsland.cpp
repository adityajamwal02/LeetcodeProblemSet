/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected
4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],
[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
*/

class Solution {
public:
    int area(vector<vector<int>> &grid, int i, int j, int n, int m){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=1)
            return 0;
        grid[i][j]=0;
    return (1+area(grid,i+1,j,n,m)+area(grid,i-1,j,n,m)+area(grid,i,j+1,n,m)+area(grid,i,j-1,n,m));
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]){
                    ans=max(ans, area(grid,i,j,n,m));
                }
            }
        }
    return ans;
    }
};


/// BFS solution

class Solution {
public:
    int delrow[4] = {1,0,-1,0};
    int delcol[4] = {0,-1,0,1};
    int count;
    void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis,int n, int m){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        count=1;
        while(!q.empty())
        {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    count++;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool> (m,0));
        int maxi=0;
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    bfs(i,j,grid,vis,n,m);
                    maxi=max(maxi, count);
                }
            }
        }
        return maxi;
    }
};
