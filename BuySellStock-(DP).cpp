class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int i=prices[0];
        int j=0;

        for(int x=1;x<prices.size();x++)
        {
            i=min(i,prices[x]);
            j=max(j,prices[x]-i);
        }
        return j;
    }
};
