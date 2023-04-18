/*
Given a square matrix[][] of size N x N. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.

Example 1:
Input:
N = 3
matrix[][] = [[1 2 3],
              [4 5 6],
              [7 8 9]]
Output:
3 6 9
2 5 8
1 4 7
Your Task:
You only need to implement the given function rotate(). Do not read input, instead use the arguments given in the function.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)
*/

/// Solution 1

//User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    int n=matrix.size(), m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int j=0;j<n;j++){
        int start=0, end=n-1;
        while(start<end){
            swap(matrix[start][j],matrix[end][j]);
            start++;
            end--;
        }
    }
}


/// Solution 2

//User function template for C++
class Solution{
public:

	void rotateMatrix(vector<vector<int>>& arr, int n) {
	    for(int i=0;i<n;i++){
            reverse(arr[i].begin(),arr[i].end());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
	}

};
