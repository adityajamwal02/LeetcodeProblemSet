/*
Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).
Note: It is assumed that negative cost cycles do not exist in the input matrix.


Example 1:
Input: grid = {{9,4,9,9},{6,7,6,4},
{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.

Example 2:
Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.

Your Task:
You don't need to read or print anything. Your task is to complete the function minimumCostPath() which takes grid as input parameter and returns the minimum cost to react at bottom right cell from top left cell.

Expected Time Compelxity: O(n2*log(n))
Expected Auxiliary Space: O(n2)
*/


/// BFS + PQ Approach




class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        int result=0, dist[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dist[i][j]=INT_MAX;
            }
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=grid[0][0];
        pq.push({dist[0][0],{0,0}});
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        while(!pq.empty()){
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            int cost=pq.top().first;
            pq.pop();
            result+=cost;
            if(i==n-1 and j==m-1){
                break;
            }
            for(int k=0;k<4;k++){
                int nrow=i+dx[k];
                int ncol=j+dy[k];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m){
                    if(dist[nrow][ncol]>=dist[i][j]+grid[nrow][ncol]){
                        dist[nrow][ncol]=dist[i][j]+grid[nrow][ncol];
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
    return dist[n-1][m-1];
    }
};


