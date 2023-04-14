/*
You are given a 0-indexed m x n integer matrix grid. Your initial position is at the top-left cell (0, 0).
Starting from the cell (i, j), you can move to one of the following cells:
Cells (i, k) with j < k <= grid[i][j] + j (rightward movement), or
Cells (k, j) with i < k <= grid[i][j] + i (downward movement).
Return the minimum number of cells you need to visit to reach the bottom-right cell (m - 1, n - 1). If there is no valid path, return -1.

Example 1:
Input: grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
Output: 4
Explanation: The image above shows one of the paths that visits exactly 4 cells.

Example 2:
Input: grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
Output: 3
Explanation: The image above shows one of the paths that visits exactly 3 cells.

Example 3:
Input: grid = [[2,1,0],[1,0,0]]
Output: -1
Explanation: It can be proven that no path exists.
*/


/// BFS + Union Find


class Solution {
public:
    int find(int x, vector<int> &arr){
        if(x==arr[x]){
            return x;
        }
    return arr[x]=find(arr[x],arr);
    }
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if(n==1 and m==1) return 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> mat_r(n, vector<int>(m+1,0)), mat_c(m, vector<int> (n+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<=m;j++){
                mat_r[i][j]=j;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<=n;j++){
                mat_c[i][j]=j;
            }
        }
        int counter=2;
        while(!q.empty()){
            int temp=q.size();
            for(int k=0;k<temp;k++){
                auto [x,y]=q.front();
                q.pop();
                int j=find(mat_r[x][y+1], mat_r[x]);
                while(j<m and j<=grid[x][y]+y){
                    if(x==n-1 and j==m-1){
                        return counter;
                    }
                    q.push({x,j});
                    mat_r[x][j]=j+1;
                    j=find(mat_r[x][j], mat_r[x]);
                }
                int i=find(mat_c[y][x+1], mat_c[y]);
                while(i<n and i<=grid[x][y]+x){
                    if(i==n-1 and y==m-1){
                        return counter;
                    }
                    q.push({i,y});
                    mat_c[y][i]=i+1;
                    i=find(mat_c[y][i], mat_c[y]);
                }
            }
            counter++;
        }
    return -1;
    }
};
