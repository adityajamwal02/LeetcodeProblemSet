/*
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
Your Task:
Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes the size of the matrix M.

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1
*/

class Solution{
  public:
    int MAH(vector<int> &arr, int n){
        vector<int> right, left, output;
        stack<pair<int, int>> st1, st2;

        // Nearest Smaller To Right
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() and st1.top().first>=arr[i]){
                st1.pop();
            }
            if(st1.empty()){
                right.push_back(n);
            }else{
                right.push_back(st1.top().second);
            }
        st1.push({arr[i],i});
        }
        reverse(right.begin(), right.end());

        // Nearest Smaller To Left
        for(int i=0;i<n;i++){
            while(!st2.empty() and st2.top().first>=arr[i]){
                st1.pop();
            }
            if(st2.empty()){
                right.push_back(-1);
            }else{
                right.push_back(st2.top().second);
            }
        st2.push({arr[i],i});
        }

        for(int i=0;i<n;i++){
            output.push_back((right[i]-left[i]-1)*arr[i]);
        }
        int ans=*max_element(output.begin(), output.end());

    return ans;
    }

    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> v;
        for(int j=0;j<m;j++){
            v.push_back(M[0][j]);
        }
        int mx=MAH(v,m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0){
                    v[j]=0;
                }else{
                    v[j]=v[j]+M[i][j];
                }
            }
        mx=max(mx,MAH(v,m));
        }
    return mx;
    }
};

