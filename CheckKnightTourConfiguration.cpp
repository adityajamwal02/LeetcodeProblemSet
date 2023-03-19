/*
There is a knight on an n x n chessboard. In a valid configuration, the knight starts at the top-left cell of the board and visits every cell on the board exactly once.
You are given an n x n integer matrix grid consisting of distinct integers from the range [0, n * n - 1] where grid[row][col] indicates that the cell (row, col) is the grid[row][col]th cell that the knight visited. The moves are 0-indexed.
Return true if grid represents a valid configuration of the knight's movements or false otherwise.
Note that a valid knight move consists of moving two squares vertically and one square horizontally, or two squares horizontally and one square vertically. The figure below illustrates all the possible eight moves of a knight from some cell.

Example 1:
Input: grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
Output: true
Explanation: The above diagram represents the grid. It can be shown that it is a valid configuration.

Example 2:
Input: grid = [[0,3,6],[5,8,1],[2,7,4]]
Output: false
Explanation: The above diagram represents the grid. The 8th move of the knight is not valid considering its position after the 7th move.
*/


class Solution {
    int r[8]={-2,-1,1,2,-2,-1,1,2};
    int c[8]={-1,-2,-2,-1,1,2,2,1};
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({0,0});
        int k=0;
        while(!q.empty()){
            int temp=0;
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int nx=x+r[i];
                int ny=y+c[i];
                if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]==k+1){
                    x=nx, y=ny;
                    temp=1;
                    break;
                }
            }
            if(temp){
                q.push({x,y});
            }
            k++;
        }
    return k==(n*m) ? 1 : 0;
    }
};
