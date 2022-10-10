/*
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
You may change 0's to 1's to connect the two islands to form one island.
Return the smallest number of 0's you must flip to connect the two islands.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
*/

class Solution {
public:
    void find(vector<vector<int>> &grid,int i,int j,set<pair<int,int>> &isl){
        if(min(i,j)<0 or max(i,j)>=grid.size() or !grid[i][j] or isl.count({i,j}))
            return;
        isl.insert({i,j});
        grid[i][j]=0;
        find(grid, i+1, j, isl);
        find(grid, i-1, j, isl);
        find(grid, i, j+1, isl);
        find(grid, i, j-1, isl);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        set<pair<int,int>> isl1,isl2;
        bool isl=true;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]){
                    if(isl){
                        find(grid,i,j,isl1);
                        isl=0;
                    }else{
                        find(grid,i,j,isl2);
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(auto [x1,y1]:isl1)
            for(auto [x2,y2]:isl2)
                ans=min(ans,abs(x1-x2)+abs(y1-y2)-1);
    return ans;
    }
};
