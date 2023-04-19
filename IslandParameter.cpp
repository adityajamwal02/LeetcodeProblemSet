/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:
Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4
*/

class Solution {
public:
    int countRegion(vector<vector<int>> &grid, int i, int j, int n, int m){
        int counter=0;
        if(i-1 < 0 or grid[i-1][j]==0) counter++;
        if(i+1 > n-1 or grid[i+1][j]==0) counter++;
        if(j-1 < 0 or grid[i][j-1]==0) counter++;
        if(j+1 > m-1 or grid[i][j+1]==0) counter++;

    return counter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    result+=countRegion(grid,i,j,n,m);
                }
            }
        }
    return result;
    }
};
