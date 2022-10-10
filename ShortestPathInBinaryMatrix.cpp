/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
Example 1:
Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
*/

class Solution {
public:
    bool isValid(int row,int col,int n){
        return row>=0 and row<n and col>=0 and col<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
            return -1;
        int n=grid.size();
        vector<vector<int>> distance(n, vector<int>(n,1e9));
        distance[0][0]=0;
        queue<pair<int, pair<int,int>> >q;
        q.push({1,{0,0}});
        int delrow[]={-1,-1,0,1,1,1,0,-1};
        int delcol[]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            auto it=q.front();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            q.pop();
            if(row==n-1 and col==n-1)
                return dis;
            for(int i=0;i<8;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(isValid(nrow,ncol,n) and grid[nrow][ncol]==0 and (dis+1<distance[nrow][ncol])){
                    distance[nrow][ncol]=dis+1;
                    q.push({dis+1, {nrow, ncol}});
                }
            }
        }
    return -1;
    }
};
