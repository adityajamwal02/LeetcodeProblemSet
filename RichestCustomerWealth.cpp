class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int i,j,sum,maxsum=0;
        int n=accounts.size();
        int m=accounts[0].size();

        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<m;j++)
            {
                sum+=accounts[i][j];
            }

            maxsum=max(sum, maxsum);
        }
        return maxsum;
    }
};
