/*
You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:
A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of times:
Catch all the fish at cell (r, c), or
Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

Example 1:
Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.

Example 2:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish.
*/

class Solution {

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

public:

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    int fishCount = 0;
                    queue<pair<int,int>> q;
                    vector<vector<bool>> visited(m, vector<bool>(n, false));

                    q.push({i,j});
                    visited[i][j] = true;

                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        if(grid[x][y] > 0) {
                            fishCount += grid[x][y];
                            grid[x][y] = 0;
                        }

                        for(int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if(nx >= 0 and nx < m and ny >= 0 and ny < n and !visited[nx][ny] and grid[nx][ny] > 0) {
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }

                    maxFish = max(maxFish, fishCount);
                }
            }
        }

    return maxFish;
    }
};
