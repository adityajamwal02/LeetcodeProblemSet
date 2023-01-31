/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

Example 1:
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Example 2:
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
*/

class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>> &board){
        return (x>=0 and x<board.size() and y>=0 and y<board[0].size());
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<int> dx={0,0,1,1,1,-1,-1,-1};
        vector<int> dy={1,-1,0,1,-1,0,1,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int liveCount=0;
                for(int k=0;k<8;k++){
                    int curr_x=i+dx[k], curr_y=j+dy[k];
                    if(isValid(curr_x, curr_y, board) and abs(board[curr_x][curr_y])==1){
                        liveCount++;
                    }
                }
                if(board[i][j]==1 and (liveCount<2 or liveCount>3)){
                    board[i][j]=-1;
                }
                if(board[i][j]==0 and liveCount==3){
                    board[i][j]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]>=1){
                    board[i][j]=1;
                }else{
                    board[i][j]=0;
                }
            }
        }
    }
};
