/*
Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or
equal to threshold or return 0 if there is no such square.

Example 1:
Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.

Example 2:
Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0
*/

class Solution {
    int squareSum(vector<vector<int>>& prefixSum, int x1, int y1, int x2, int y2) {
        return prefixSum[x2][y2] - prefixSum[x1][y2] - prefixSum[x2][y1] + prefixSum[x1][y1];
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // compute prefixSum via dynamic-programming method
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefixSum(m+1, vector<int>(n+1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        int res = 0;

        for (int i = 0; i < m; i ++) {
            // do sliding-window on the diagonal line of (i, 0), (i+1, 1), ...
            int begin = 0, end = 0;
            int x1, x2, y1, y2;
            while (i+end <= m && end <= n) {
                x1 = i+begin, y1 = begin, x2 = i+end, y2 = end;
                while (begin < end && squareSum(prefixSum, x1, y1, x2, y2) > threshold) {
                    begin ++;
                    x1 = i+begin, y1 = begin;
                }
                res = max(res, end - begin);
                end ++;
            }
        }

        for (int i = 1; i < n; i ++) {
            // do sliding-window on the diagonal line of (0, i), (1, i+1), ...
            int begin = 0, end = 0;
            int x1, x2, y1, y2;
            while (end <= m && i+end <= n) {
                x1 = begin, y1 = i+begin, x2 = end, y2 = i+end;
                while (begin < end && squareSum(prefixSum, x1, y1, x2, y2) > threshold) {
                    begin ++;
                    x1 = begin, y1 = i+begin;
                }
                res = max(res, end - begin);
                end ++;
            }
        }
        return res;
    }
};
