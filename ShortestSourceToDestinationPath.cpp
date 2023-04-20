/*
Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.

Example 1:

Input:
N=3
M=4
A=[[1,0,0,0],
[1,1,0,1],[0,1,1,1]]
X=2
Y=3
Output:
5
Explanation:
The shortest path is as follows:
(0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).
Example 2:

Input:
N=3
M=4
A=[[1,1,1,1],
[0,0,0,1],[0,0,0,1]]
X=0
Y=3
Output:
3
Explanation:
The shortest path is as follows:
(0,0)->(0,1)->(0,2)->(0,3).

Your Task:
You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.


Expected Time Complexity:O(N*M)
Expected Auxillary Space:O(N*M)
*/

// User function Template for C++

class Solution {
  public:

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0]==0) return -1;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(N, vector<int>(M,INT_MAX));
        dist[0][0]=0;
        q.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            int steps=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 and ncol>=0 and nrow<N and ncol<M and A[nrow][ncol]==1 and steps+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=steps+1;
                    if(nrow==X and ncol==Y){
                        return dist[nrow][ncol];
                    }else{
                        q.push({steps+1,{nrow,ncol}});
                    }
                }
            }
        }
    return -1;
    }
};
