/*
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Example 2:
Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> an;
        for(int i=0;i<mp.size();i++){
            if(i%2==0){
                reverse(mp[i].begin(), mp[i].end());
            }
            for(auto x: mp[i]){
                an.push_back(x);
            }
        }
    return an;
    }
};
