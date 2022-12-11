/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean.
The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where
heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east,
and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from
any cell adjacent to an ocean into the ocean. Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that
rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

Example 2:
Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
*/

class Solution {
public:

    void dfs(int i, int j, vector<vector<int>> &heights, vector<vector<bool>> &ocean){
        int n=heights.size();
        int m=heights[0].size();
        if(ocean[i][j]==false){
            ocean[i][j]=true;
            if(i>0 and heights[i-1][j]>=heights[i][j] and ocean[i-1][j]==false){
                dfs(i-1,j,heights,ocean);
            }
            if(j>0 and heights[i][j-1]>=heights[i][j] and ocean[i][j-1]==false){
                dfs(i,j-1,heights,ocean);
            }
            if(i<n-1 and heights[i+1][j]>=heights[i][j] and ocean[i+1][j]==false){
                dfs(i+1,j,heights,ocean);
            }
            if(j<m-1 and heights[i][j+1]>=heights[i][j] and ocean[i][j+1]==false){
                dfs(i,j+1,heights,ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> pacific(n+1,vector<bool>(m+1,false));
        vector<vector<bool>> atlantic(n+1,vector<bool>(m+1,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0){
                    dfs(i,j,heights,pacific);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1 or j==m-1){
                    dfs(i,j,heights,atlantic);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] and atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
    return ans;
    }
};
