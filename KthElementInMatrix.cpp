/*
Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.


Example 2:
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.

Your Task:
You don't need to read input or print anything. Complete the function kthsmallest() which takes the mat, N and K as input parameters and returns the kth smallest element in the matrix.

Expected Time Complexity: O(K*Log(N))
Expected Auxiliary Space: O(N)
*/

/// Binary Search (O(K*Log(N))

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low=mat[0][0], high=mat[n-1][n-1];
    while(low<high){
        int mid=low+(high-low)/2;
        int count=0;
        for(int i=0;i<n;i++){
            count+=upper_bound(mat[i], mat[i]+n, mid)-mat[i];
        }
        if(count<k){
            low=mid+1;
        }else{
            high=mid;
        }
    }
return low;
}


/// priority_queue solution (O(n^2))

int kthSmallest(int arr[MAX][MAX], int n, int k)
{
  priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pq.push(arr[i][j]);
            }
        }
        int num=0;
        while(k){
            num=pq.top();
            pq.pop();
            k--;
        }
        return num;
}
