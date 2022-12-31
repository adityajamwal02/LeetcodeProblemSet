/*
You are given an m x n integer array grid where grid[i][j] could be:
1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Example 1:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:
Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
*/

class Solution {
public:
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool isValid(int i, int j){
        return i>=0 and j>=0 and i<n and j<m;
    }

    int dfs(int i, int j, int left, pair<int, int> dest, vector<vector<int>> &grid){
        if(left==-1 and pair<int, int>(i,j)==dest){
            return 1;
        }
        grid[i][j]=-1;
        int ans=0;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];

            if(isValid(x,y) and grid[x][y]!=-1){
                ans+=dfs(x,y,left-1,dest,grid);
            }
        }
        grid[i][j]=0;
    return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        pair<int, int> src, dest;
        int empty=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) empty++;
                if(grid[i][j]==1) src={i,j};
                if(grid[i][j]==2) dest={i,j};
            }
        }
    return dfs(src.first, src.second, empty, dest, grid);
    }
};
