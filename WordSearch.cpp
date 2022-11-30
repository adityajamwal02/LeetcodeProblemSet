/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/


class Solution {
public:
    bool dfs(int i, int j, int count, vector<vector<char>> &board, string word){
        if(word.size()==count){
            return true;
        }
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[count]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]=' ';
        bool ans = dfs(i-1,j,count+1,board,word) or 
                   dfs(i+1,j,count+1,board,word) or
                   dfs(i,j-1,count+1,board,word) or 
                   dfs(i,j+1,count+1,board,word);

        board[i][j]=temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] and dfs(i,j,0,board,word)){
                    return true;
                }
            }
        }
    return false;
    }
};

