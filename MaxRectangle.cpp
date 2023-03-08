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
*/
/*You are required to complete this method*/

class Solution{
  public:
    int MAH(vector<int> &height){
        stack<int> st;
        int maxA=0;
        int n=height.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i==n or height[st.top()]>=height[i])){
                int h=height[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }else{
                    width=i-st.top()-1;
                }
                maxA=max(maxA,h*width);
            }
        st.push(i);
        }
    return maxA;
    }

    int maxArea(int M[MAX][MAX], int n, int m) {
        int maxArea=0;
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==1){
                    height[j]++;
                }else{
                    height[j]=0;
                }
            }
            int area = MAH(height);
            maxArea=max(area,maxArea);
        }
    return maxArea;
    }
};
