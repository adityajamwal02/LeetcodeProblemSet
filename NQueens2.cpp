/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:
Input: n = 1
Output: 1
*/

/// Solution 1 (BackTracking)

class Solution {
public:
    void helper(int col, int n, int &counter, vector<string> &temp, vector<int> &left, vector<int> &lower, vector<int> &upper){
        if(col==n){
            counter++;
            return;
        }
        for(int i=0;i<n;i++){
            if(left[i]==0 and lower[i+col]==0 and upper[n-1+col-i]==0){
                left[i]=1;
                lower[i+col]=1;
                upper[n-1+col-i]=1;
                temp[i][col]='Q';

                helper(col+1,n,counter,temp,left,lower,upper);

                left[i]=0;
                lower[i+col]=0;
                upper[n-1+col-i]=0;
                temp[i][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int counter=0;
        string s(n,'.');
        vector<string> temp(n,s);
        vector<int> leftRow(n,0), lowerDiagnol(2*n-1,0), upperDiagnol(2*n-1,0);
    helper(0,n,counter,temp,leftRow,lowerDiagnol,upperDiagnol);
    return counter;
    }
};
