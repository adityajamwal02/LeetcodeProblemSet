/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0
There are two islands :- one is colored in blue
and other in orange.
Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number of islands.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)
*/


class Solution {
  public:
    // Function to find the number of islands.

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
            for(int k=0;k<8;k++){
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
        int n=grid.size(), m=grid[0].size();
        int counter=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<int> delrow, delcol;
        delrow={-1,-1,-1,0,0,1,1,1};
        delcol={-1,0,1,-1,1,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                    counter++;
                    bfs(i,j,vis,grid,delrow,delcol);
                }
            }
        }
    return counter;
    }
};
