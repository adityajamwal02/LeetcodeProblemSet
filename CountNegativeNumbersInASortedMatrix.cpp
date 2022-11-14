/*
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0
*/

/// Brute Force Approach

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]<0)
                    count++;
            }
        }
    return count;
    }
};

/// Binary Search Approach

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(const vector<int> &row : grid){
            count+=upper_bound(row.rbegin(), row.rend(), -1) - row.rbegin();
        }
    return count;
    }
};
