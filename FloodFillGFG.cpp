/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.
Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

Example 1:
Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image
(with position (sr, sc) = (1, 1)), all
pixels connected by a path of the same color
as the starting pixel are colored with the new
color.Note the bottom corner is not colored 2,
because it is not 4-directionally connected to
the starting pixel.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function floodFill() which takes image, sr, sc and newColor as input paramater and returns the image after flood filling.

Expected Time Compelxity: O(n*m)
Expected Space Complexity: O(n*m)
*/


/// DFS

class Solution {
public:

    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};

    void dfs(int i, int j, int n, int m, vector<vector<int>> &result, vector<vector<int>> &image, int newColor, int initialColor){
        result[i][j]=newColor;
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 and ncol>=0 and ncol<m and nrow<n and result[nrow][ncol]!=newColor and image[nrow][ncol]==initialColor){
                dfs(nrow,ncol,n,m,result,image,newColor,initialColor);
            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialColor=image[sr][sc];
        int n=image.size(), m=image[0].size();
        vector<vector<int>> result=image;
        dfs(sr,sc,n,m,result,image,newColor,initialColor);
    return result;
    }
};


/// BFS

class Solution {
public:
    void bfs(int x,int y,int newcol,int oldcol,
    vector<vector<int>> &vis,vector<vector<int>> &ans){
        vis[x][y] = 1;
        ans[x][y] = newcol;
        int n = ans.size();
        int m = ans[0].size();
        queue<pair<int,int>>q;
        q.push({x,y});
        while(!q.empty()){
            int xc = q.front().first;
            int yc = q.front().second;
            q.pop();
            vector<int> xcor = {0,-1,0,1};
            vector<int> ycor = {-1,0,1,0};
            for(int i=0;i<4;i++){
                int newr = xc+xcor[i];
                int newc = yc+ycor[i];
                if(newr>=0 && newc>=0 && newr<n && newc<m &&  !vis[newr][newc] && ans[newr][newc]==oldcol){
                    ans[newr][newc] = newcol;
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                }
            }
        }
    }
