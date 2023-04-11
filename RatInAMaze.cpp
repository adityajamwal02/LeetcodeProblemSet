/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at
(3, 3) from (0, 0) by two paths - DRDDRR
and DDRDRR, when printed in sorted order
we get DDRDRR DRDDRR.

Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is
blocked.
Your Task:
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order.
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.
*/

// User function template for C++

class Solution{
    public:

    void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &result, string temp, vector<vector<int>> &vis){
        if(i==n-1 and j==n-1){
            result.push_back(temp);
            return;
        }

        if(i+1<n and !vis[i+1][j] and m[i+1][j]==1){
            vis[i][j]=1;
            solve(i+1,j,m,n,result,temp+'D',vis);
            vis[i][j]=0;
        }

        if(j-1>=0 and !vis[i][j-1] and m[i][j-1]==1){
            vis[i][j]=1;
            solve(i,j-1,m,n,result,temp+'L',vis);
            vis[i][j]=0;
        }

        if(j+1<n and !vis[i][j+1] and m[i][j+1]==1){
            vis[i][j]=1;
            solve(i,j+1,m,n,result,temp+'R',vis);
            vis[i][j]=0;
        }

        if(i-1>=0 and !vis[i-1][j] and m[i-1][j]==1){
            vis[i][j]=1;
            solve(i-1,j,m,n,result,temp+'U',vis);
            vis[i][j]=0;
        }

    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        vector<vector<int>> vis(n, vector<int>(n,0));
        if(m[0][0]==1){
            solve(0,0,m,n,result,"",vis);
        }
    return result;
    }
};


