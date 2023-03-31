/*
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

Example 1:
Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.

Example 2:
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
*/

/// PQ + Djkstra

class Solution {
public:

    bool isValid(int r,int c,int n){
        if(r>=0 && r<n && c>=0 && c<n){
            return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        vector<int> dir{-1,0,1,0,-1};
        dist[0][0]=grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({grid[0][0],{0,0}});
        while(!q.empty()){
            int d=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;
            q.pop();
            for(int k=0;k<dir.size()-1;k++){
                int c_r=r+dir[k];
                int c_c=c+dir[k+1];
                if(isValid(c_r,c_c,n)){
                    if(d<grid[c_r][c_c]){
                        if(dist[c_r][c_c]>grid[c_r][c_c]){
                            dist[c_r][c_c]=grid[c_r][c_c];
                            q.push({dist[c_r][c_c],{c_r,c_c}});
                        }

                    }else if(d>grid[c_r][c_c]){
                        if(dist[c_r][c_c]>d){
                            dist[c_r][c_c]=d;
                            q.push({dist[c_r][c_c],{c_r,c_c}});
                        }

                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};

/// Binary Search + BFS

class Solution {
public:
    vector<vector<int>> moves={{0,1},{0,-1},{-1,0},{1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int l=0, r=n*n-1, result=n*n;
        if(n==1) return grid[0][0];
        while(l<=r){
            int mid=l+(r-l)/2;
            queue<vector<int>> q;
            if(grid[0][0]>mid){
                l=mid+1;
                continue;
            }
            q.push({0,0});
            vector<vector<bool>> vis(n,vector<bool>(n,false));
            vis[0][0]=true;
            bool flag=false;
            while(!q.empty()){
                int x=q.front()[0], y=q.front()[1];
                q.pop();
                for(auto z : moves){
                    int x_new=x+z[0], y_new=y+z[1];
                    if(x_new<0 or y_new<0 or x_new>=n or y_new>=n or vis[x_new][y_new] or grid[x_new][y_new]>mid) continue;
                    vis[x_new][y_new]=true;
                    q.push({x_new,y_new});
                    if(x_new==n-1 and y_new==n-1){
                        flag=true;
                        break;
                    }
                }
            }
        if(flag){
            result=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return result;
    }
};

