/*
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}
Output:
3
Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.

Example 2:
Input:
grid[][] = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}}
Output:
4
Explanation:
0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0
The highlighted cells represents the land cells.
Your Task:

You don't need to print or input anything. Complete the function numberOfEnclaves() which takes a 2D integer matrix grid as the input parameter and returns an integer, denoting the number of land cells.
Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)
*/

/// BFS

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or i==n-1 or j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=row+delrow[k];
                int ncol=col+delcol[k];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        int counter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and grid[i][j]==1){
                    counter++;
                }
            }
        }
    return counter;
    }
};

/// DFS

// User function Template for C++

class Solution {
  public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid){
        if(i>n-1 or j>m-1 or i<0 or j<0 or grid[i][j]!=1){
            return;
        }
        grid[i][j]=-1;
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            dfs(nrow,ncol,n,m,grid);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or i==n-1 or j==m-1){
                    dfs(i,j,n,m,grid);
                }
            }
        }
        int counter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    counter++;
                }
            }
        }
    return counter;
    }
};
