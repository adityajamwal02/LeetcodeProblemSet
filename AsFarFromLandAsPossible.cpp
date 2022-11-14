/*
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land,
find a water cell such that its distance to the nearest land cell is maximized, and return the distance.
If no land or water exists in the grid, return -1.
The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Example 1:
Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

Example 2:
Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
*/

class Solution {
public:
    int n;
    vector<vector<int>> dist;
    void dfs(vector<vector<int>> &grid, int i, int j, int d){
        dist[i][j]=d;
        d++;
        if(i+1<n and grid[i+1][j]==0 and dist[i+1][j]>d)
            dfs(grid, i+1, j, d);
        if(i>0 and grid[i-1][j]==0 and dist[i-1][j]>d)
            dfs(grid, i-1, j, d);
        if(j+1<n and grid[i][j+1]==0 and dist[i][j+1]>d)
            dfs(grid, i, j+1, d);
        if(j>0 and grid[i][j-1]==0 and dist[i][j-1]>d)
            dfs(grid, i, j-1, d);
    }

    int maxDistance(vector<vector<int>>& grid) {
        n=grid.size();
        dist=vector<vector<int>> (n,vector<int>(n,1000));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    dfs(grid,i,j,0);
            }
        }

        int ans=0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                ans=max(ans,dist[i][j]);
            }
        }
        if(ans==0 or ans==1000){
            return -1;
        }
    return ans;
    }
};

