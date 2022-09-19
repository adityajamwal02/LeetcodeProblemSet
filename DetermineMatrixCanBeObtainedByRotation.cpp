/*
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments,
or false otherwise.

Example 1:
Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.

Example 2:
Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.

Example 3:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
*/

class Solution {
public:

    bool check(vector<vector<int>> &mat, vector<vector<int>> &target){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]!=target[i][j])
                    return false;
            }
        }
    return true;
    }

    void rotate(vector<vector<int>> &mat){
        int n=mat.size();
        for(int i=0;i<=n/2;i++){
            for(int j=i;j<n-i-1;j++){
                int temp=mat[n-j-1][i];
                mat[n-j-1][i]=mat[n-i-1][n-j-1];
                mat[n-i-1][n-j-1]=mat[j][n-i-1];
                mat[j][n-i-1]=mat[i][j];
                mat[i][j]=temp;
            }
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
            for(int i=0;i<4;i++){
                rotate(mat);
                if(check(mat, target))
                    return true;
            }
    return false;
    }
};
