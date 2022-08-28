/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!matrix[i][j]){
                    matrix[i][0]=0;
                    if(j) matrix[0][j]=0;
                    else flag=true;
                }
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<m;j++) matrix[i][j]=0;
            }
        }
        for(int j=1;j<m;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<n;i++) matrix[i][j]=0;
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<m;j++) matrix[0][j]=0;
        }
        if(flag){
            for(int i=0;i<n;i++) matrix[i][0]=0;
        }
    }
};
