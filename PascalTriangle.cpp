class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> pascal(numRows);
        for(int i=0;i<numRows;i++)
        {
            pascal[i].resize(i+1);
            pascal[i][0]=pascal[i][i]=1;
            for(int j=1;j<i;j++)
                pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
        }
        return pascal;
    }
};
