/*
Given a matrix of  size n x m. Your task is to make Zeroes, that means in whole matrix when you find a zero, convert its upper, lower, left, and right value to zero and make that element the sum of the upper, lower, left and right value. Do the following tasks according to the initial matrix.

Example 1:
Input: matrix = {{1, 2, 3, 4},
                 {5, 6, 0, 7},
                 {8, 9, 4, 6},
                 {8, 4, 5, 2}}
Output: {{1, 2, 0, 4},
         {5, 0, 20, 0},
         {8, 9, 0, 6},
         {8, 4, 5, 2}}
Explanation: As matrix[1][2] = 0, we will
perform the operation here. Then matrix[1][2]
= matrix[0][2] + matrix[2][2] + matrix[1][1]
+ matrix[1][3] and matrix[0][2] = matrix[2][2]
= matrix[1][1] = matrix[1][3] = 0.

Example 2:
Input: matrix = {{1, 2},
                 {3, 4}}
output: {{1, 2},
         {3, 4}}

Your Task:
You don't need to read or print anything. Your task is to complete the function MakeZeros() which takes the matrix as input parameter and does the given task according to initial matrix. You don't need to return anything. The driver code prints the modified matrix itself in the output.
Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)
*/

/// Brute

//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        int sum;
        vector<vector<int>> vec(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum=0;
                if(matrix[i][j]==0){
                    if(i>0){
                        vec[i-1][j]=-1;
                        sum+=matrix[i-1][j];
                    }
                    if(j>0){
                        vec[i][j-1]=-1;
                        sum+=matrix[i][j-1];
                    }
                    if(i<n-1){
                        vec[i+1][j]=-1;
                        sum+=matrix[i+1][j];
                    }
                    if(j<m-1){
                        vec[i][j+1]=-1;
                        sum+=matrix[i][j+1];
                    }
                }
                if(matrix[i][j]==0){
                    vec[i][j]=sum;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vec[i][j]==0){
                    vec[i][j]=matrix[i][j];
                }else if(vec[i][j]==-1){
                    vec[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=vec[i][j];
            }
        }
    }
};
