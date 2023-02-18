/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:
Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we
have only 1 distinct island.

Example 2:
Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Your Task:

You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)
*/


void dfs(int r, int c, const int iR, const int iC, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &temp) {
    int row = grid.size();
    int col = grid[0].size();

    static vector<int> delRow {-1, 0, 1, 0};
    static vector<int> delCol {0, 1, 0, -1};

    visited[r][c] = 1;

    temp.push_back({r-iR, c-iC});

    for(int i=0;i<4;i++) {
        int nr = r + delRow[i];
        int nc = c + delCol[i];

        if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 1 && visited[nr][nc] == 0) {
            dfs(nr, nc, iR, iC, visited, grid, temp);
        }
    }
}
int countDistinctIslands(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    set<vector<pair<int, int>>> s;
    vector<vector<int>> visited(row, vector<int>(col, 0));

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(visited[i][j] == 0 && grid[i][j] == 1) {
                vector<pair<int, int>> temp;
                dfs(i, j, i, j, visited, grid, temp);
                s.insert(temp);
            }
        }
    }
    return s.size();
}
