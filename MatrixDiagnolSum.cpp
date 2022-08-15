class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

       int ans=0;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if((i==j) or (i+j==mat.size()-1))
                    ans+=mat[i][j];
            }
        }

    return ans;
    }
};
