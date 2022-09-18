/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and
sell on day 6 (price = 3), profit = 3-0 = 3.
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(k==0 or n<2)
            return 0;
        int maxProfit=0;
        if(n<2*k){
            for(int i=1;i<n;i++){
                if(prices[i-1]<prices[i]){
                    maxProfit+=prices[i]-prices[i-1];
                }
            }
        return maxProfit;
        }

        vector<int> dp((2*k)+1);
        dp[0]=-prices[0];
        for(int i=1;i<2*k;i++){
            if(i%2==0)
                dp[i]=INT_MIN;
            else
                dp[i]=0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<2*k;j++){
                if(j==0){
                    dp[j]=max(dp[j], -prices[i]);
                }
                else if(j%2==0){
                    dp[j]=max(dp[j], dp[j-1]-prices[i]);
                }else{
                    dp[j]=max(dp[j], dp[j-1]+prices[i]);
                }
            }
        }
    return dp[2*k-1];
    }
};
