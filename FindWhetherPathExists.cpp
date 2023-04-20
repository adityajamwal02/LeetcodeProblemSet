/*
Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.


Example 1:

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
Explanation: The grid is-
3 0 3 0 0
3 0 0 0 3
3 3 3 3 3
0 2 3 0 0
3 0 0 1 3
There is no path to reach at (3,1) i,e at
destination from (4,3) i,e source.
Example 2:

Input: grid = {{1,3},{3,2}}
Output: 1
Explanation: The grid is-
1 3
3 2
There is a path from (0,0) i,e source to (1,1)
i,e destination.


Your Task:
You don't need to read or print anything. Your task is to complete the function is_Possible() which takes the grid as input parameter and returns boolean value 1 if there is a path otherwise returns 0.


Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

*/


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid)
    {
        int src_i, src_j, dest_i, dest_j;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    src_i=i;
                    src_j=j;
                }
                if(grid[i][j]==2){
                    dest_i=i;
                    dest_j=j;
                }
            }
        }
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({src_i,src_j});
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x=row+dr[i];
                int y=col+dc[i];
                if(x>=n || x < 0|| y >= n || y < 0 || grid[x][y]==0 || vis[x][y])
                    continue;
                if(grid[x][y] == 2) return 1;
                q.push({x, y});
                vis[x][y] = 1;
            }
        }
        return 0;
    }
};
