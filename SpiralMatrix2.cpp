/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int row_start=0, row_end=n-1, column_start=0, column_end=n-1;
        int upd=0;
        while(row_start<=row_end and column_start<=column_end)
        {
        for(int col=column_start; col<=column_end; col++)
            mat[row_start][col]=++upd;
        row_start++;
        for(int row=row_start; row<=row_end; row++)
            mat[row][column_end]=++upd;
        column_end--;
        if(row_start<row_end and column_start<column_end){
            for(int col=column_end; col>=column_start; col--)
                mat[row_end][col]=++upd;
            row_end--;
            for(int row=row_end; row>=row_start; row--)
                mat[row][column_start]=++upd;
            column_start++;
            }
        }
    return mat;
    }
};
