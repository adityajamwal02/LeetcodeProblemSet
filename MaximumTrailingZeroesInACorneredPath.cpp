/*
You are given a 2D integer array grid of size m x n, where each cell contains a positive integer.
A cornered path is defined as a set of adjacent cells with at most one turn. More specifically, the path should exclusively move either horizontally or vertically up to the turn (if there is one), without returning to a previously visited cell. After the turn, the path will then move exclusively in the alternate direction: move vertically if it moved horizontally, and vice versa, also without returning to a previously visited cell.
The product of a path is defined as the product of all the values in the path.
Return the maximum number of trailing zeros in the product of a cornered path found in grid.
Note:
Horizontal movement means moving in either the left or right direction.
Vertical movement means moving in either the up or down direction.

Example 1:
Input: grid = [[23,17,15,3,20],[8,1,20,27,11],[9,4,6,2,21],[40,9,1,10,6],[22,7,4,5,3]]
Output: 3
Explanation: The grid on the left shows a valid cornered path.
It has a product of 15 * 20 * 6 * 1 * 10 = 18000 which has 3 trailing zeros.
It can be shown that this is the maximum trailing zeros in the product of a cornered path.
The grid in the middle is not a cornered path as it has more than one turn.
The grid on the right is not a cornered path as it requires a return to a previously visited cell.

Example 2:
Input: grid = [[4,3,2],[7,6,1],[8,8,8]]
Output: 0
Explanation: The grid is shown in the figure above.
There are no cornered paths in the grid that result in a product with a trailing zero.
*/


/// 1st Solution

class Solution {
public:
    pair<long long, long long> helper(int val){
        int x=0;
        while(val>0 and val%5==0){
            val=val/5;
            x++;
        }
        int y=0;
        while(val>0 and val%2==0){
            val=val/2;
            y++;
        }
    return {x,y};
    }
    long long util(vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        pair<long long, long long> mat[n][m];
        pair<long long, long long> mat1[n][m];
        pair<long long, long long> mat2[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=grid[i][j];
                mat[i][j]=helper(val);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(j==m-1)
                    mat1[i][j]=mat[i][j];
                else
                    mat1[i][j]={mat[i][j].first+mat1[i][j+1].first,mat[i][j].second+mat1[i][j+1].second};

            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0)
                    mat2[i][j]=mat[i][j];
                else
                    mat2[i][j]={mat[i][j].first+mat2[i][j-1].first,mat[i][j].second+mat2[i][j-1].second};
            }
        }
        long long res=0;

        for(int j=0;j<m;j++){
            pair<long long,long long>sum={0,0};
            for(int i=0;i<n;i++){
                sum={sum.first+mat[i][j].first,sum.second+mat[i][j].second};
                res=max(res,min(sum.first,sum.second));
                if(j>0){
                pair<long long,long long>p1=mat2[i][j-1];
                res=max(res,min(sum.first+p1.first,sum.second+p1.second));
                }
                if(j<m-1){
                    pair<long long,long long>p1=mat1[i][j+1];
                res=max(res,min(sum.first+p1.first,sum.second+p1.second));
                }

            }

        }
        return res;
    }
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> grid2(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid2[i][j]=grid[i][j];
            }
        }
        long long res=0;
        res=max(util(grid), util(grid2));
        vector<vector<int>> grid3(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid3[n-i-1][j]=grid[i][j];
            }
        }
    return max(res, util(grid3));
    }
};


///  2nd Solution

/*
    Time: O(n*m)
    Space: O(n*m)
    Tag: Prefix Sum, Matrix, Implementation
    Difficulty: MH
*/

class Solution {
public:
    int factOf5(int num) {
        int res = 0;
        while (num && num % 5 == 0) {
            res++;
            num /= 5;
        }
        return res;
    }
    int factOf2(int num) {
        int res = 0;
        while (num && num % 2 == 0) {
            res++;
            num /= 2;
        }
        return res;
    }

    int maxTrailingZeros(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> fives(n, vector<int>(m));
        vector<vector<int>> twos(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                fives[i][j] = factOf5(grid[i][j]);
                twos[i][j] = factOf2(grid[i][j]);
            }
        }
        vector<vector<int>> prefvert5(n + 1, vector<int>(m + 1));
        vector<vector<int>> prefvert2(n + 1, vector<int>(m + 1));
        vector<vector<int>> prefhoriz5(n + 1, vector<int>(m + 1));
        vector<vector<int>> prefhoriz2(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    prefhoriz5[i][j] == 0;
                    prefhoriz2[i][j] == 0;
                } else {
                    prefhoriz5[i][j] = prefhoriz5[i][j - 1] + fives[i - 1][j - 1];
                    prefhoriz2[i][j] = prefhoriz2[i][j - 1] + twos[i - 1][j - 1];
                }
            }
        }
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    prefvert5[j][i] == 0;
                    prefvert2[j][i] == 0;
                } else {
                    prefvert5[j][i] = prefvert5[j - 1][i] + fives[j - 1][i - 1];
                    prefvert2[j][i] = prefvert2[j - 1][i] + twos[j - 1][i - 1];
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int vertdown2 = prefvert2[n][j + 1] - prefvert2[i][j + 1];
                int vertdown5 = prefvert5[n][j + 1] - prefvert5[i][j + 1];
                int vertup2 = prefvert2[i + 1][j + 1];
                int vertup5 = prefvert5[i + 1][j + 1];

                int horizleft2 = prefhoriz2[i + 1][j + 1];
                int horizleft5 = prefhoriz5[i + 1][j + 1];
                int horizRight2 = prefhoriz2[i + 1][m] - prefhoriz2[i + 1][j];
                int horizRight5 = prefhoriz5[i + 1][m] - prefhoriz5[i + 1][j];

                int res1 = min(horizleft2 + vertup2 - twos[i][j], horizleft5 + vertup5 - fives[i][j]);
                int res2 = min(horizleft2 + vertdown2 - twos[i][j], horizleft5 + vertdown5 - fives[i][j]);
                int res3 = min(horizRight2 + vertup2 - twos[i][j], horizRight5 + vertup5 - fives[i][j]);
                int res4 = min(horizRight2 + vertdown2 - twos[i][j], horizRight5 + vertdown5 - fives[i][j]);
                res = max(res, max(res1, max(res2, max(res3, res4))));
            }
        }

        return res;
    }
};
