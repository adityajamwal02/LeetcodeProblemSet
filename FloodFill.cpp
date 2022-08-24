/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting
pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color),
and so on. Replace the color of all of the aforementioned pixels with color.
Return the modified image after performing the flood fill.
*/


class Solution {
public:

    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>>& image,
             int newColor, int delrow[], int delcol[], int iniColor){
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==iniColor and ans[nrow][ncol]!=newColor)
                dfs(nrow, ncol, ans, image, newColor, delrow, delcol, iniColor);
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr, sc, ans, image, newColor, delrow, delcol, iniColor);
        return ans;
    }
};
