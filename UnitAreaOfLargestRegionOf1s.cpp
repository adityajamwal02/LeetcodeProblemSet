/*
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).

Example 1:

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1
The largest region of 1's is colored
in orange.
Example 2:

Input: grid = {{0,1}}
Output: 1
Explanation: The grid is-
0 1
The largest region of 1's is colored in
orange.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function findMaxArea() which takes grid as input parameter and returns the area of the largest region of 1's.


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
*/

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dr[]={-1,-1,-1,0,0,1,1,1};
        int dc[]={-1,0,1,-1,1,0,1,-1};
        queue<pair<int,int>> q;
        int curr=0, result=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    curr=0;
                    q.push({i,j});
                    vis[i][j]=1;
                }
                while(!q.empty()){
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    curr++;
                    for(int k=0;k<8;k++){
                        int nrow=row+dr[k];
                        int ncol=col+dc[k];
                        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]!=1 and grid[nrow][ncol]==1){
                            q.push({nrow,ncol});
                            vis[nrow][ncol]=1;
                        }
                    }
                }
            result=max(result,curr);
            }
        }
    return result;
    }
};
