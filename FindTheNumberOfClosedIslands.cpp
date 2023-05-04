/*
Given a binary matrix mat[][] of dimensions NxM such that 1 denotes land and 0 denotes water. Find the number of closed islands in the given matrix.

A closed island is known as the group of 1s
that is surrounded by only 0s on all the four
sides (excluding diagonals). If any 1 is at
the edges of the given matrix then it is not
considered as the part of the connected
island as it is not surrounded by all 0's.

Example 1:

Input:
N = 5, M = 8
mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1},
           {0, 1, 1, 1, 1, 0, 0, 1},
           {0, 1, 0, 1, 0, 0, 0, 1},
           {0, 1, 1, 1, 1, 0, 1, 0},
           {0, 0, 0, 0, 0, 0, 0, 1}}
Output:
2
Explanation:
mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1},
           {0, 1, 1, 1, 1, 0, 0, 1},
           {0, 1, 0, 1, 0, 0, 0, 1},
           {0, 1, 1, 1, 1, 0, 1, 0},
           {0, 0, 0, 0, 0, 0, 0, 1}}
There are 2 closed islands.
The islands in dark are closed because
they are completely surrounded by 0s (water).
There are two more islands in the last
column of the matrix, but they are not
completely surrounded by 0s.
Hence they are not closed islands.
Example 2:

Input:
N = 3, M = 3
mat[][] = {{1, 0, 0},
           {0, 1, 0},
           {0, 0, 1}}
Output:
1

Your task:
You dont need to read input or print anything. Your task is to complete the function closedIslands() which takes two integers N and M, and a 2D binary matrix mat as input parameters and returns the number of closed islands.


Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)
*/


class Solution {
    public:
     int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};

    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or vis[i][j]==1 or grid[i][j]==0)
            return;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            dfs(nrow,ncol,vis,grid);
        }
    }
    int closedIslands(vector<vector<int>>& grid, int N, int M) {
        int n=N, m=M;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 or j==0 or i==n-1 or j==m-1) and !vis[i][j]){
                    dfs(i,j,vis,grid);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
    return count;
    }
};
