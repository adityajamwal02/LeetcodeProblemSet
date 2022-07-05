class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat[0].size() * mat.size() != r*c) return mat;
        vector<vector<int>> res(r,vector<int> (c));
        int resC=0;
        int resR=0;
        for(int i=0;i<mat.size();++i)
        {
            for(int j=0;j<mat[0].size();++j)
            {
                if(resC==c)
                {
                    resC=0;
                    ++resR;
                }
                res[resR][resC]=mat[i][j];
                ++resC;
            }
        }
        return res;

    }
};
