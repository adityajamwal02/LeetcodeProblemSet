/*
Given two integers M, N, and a 2D matrix Mat of dimensions MxN, clockwise rotate the elements in it.

Example 1:
Input:
M=3,N=3
Mat=[[1,2,3],[4,5,6],[7,8,9]]
Output:
4 1 2
7 5 3
8 9 6
Explanation:
Rotating the matrix clockwise gives this result.

Example 2:
Input:
M=2,N=3
Mat=[[1,2,3],[2,3,3]]
Output:
2 1 2
3 3 3
Explanation:
Rotating the matrix clockwise gives this result.

Your Task:
You don't need to read input or print anything. Your task is to complete the function rotateMatrix() which takes two integers M, N, and a 2D matrix as input parameters and returns the clockwise rotated matrix.

Expected Time Complexity:O(M*N)
Expected Auxillary Space:O(1)
*/

// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int n, int m, vector<vector<int>> arr) {
         int top=0, bottom=n-1, left=0, right=m-1;

        int i;

        while(top<bottom && left<right) {

            int temp=arr[top+1][left];

            for(i=left; i<=right; i++){

                swap(arr[top][i], temp);

            }

            top++;

            for(i=top; i<=bottom; i++){

                swap(arr[i][right], temp);

            }

            right--;

            for(i=right; i>=left; i--){

                swap(arr[bottom][i], temp);

            }

            bottom--;

            for(i=bottom; i>=top; i--){

                swap(arr[i][left], temp);

            }

            left++;

        }

        return arr;

    }
};
