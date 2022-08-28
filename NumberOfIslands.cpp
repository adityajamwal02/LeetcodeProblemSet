/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

class Solution {
public:
    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid, vector<int> &delrow, vector<int> &delcol){
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int, int>> q;
        q.push({i,j});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];
                if(nrow>=0 and nrow <n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<int> delrow,delcol;
        delrow={-1,1,0,0};
        delcol={0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                    count++;
                    bfs(i,j,vis,grid,delrow,delcol);
                }
            }
        }
    return count;
    }
};
