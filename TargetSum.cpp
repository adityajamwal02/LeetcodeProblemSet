/*
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1
*/

/// Approach 1 : Subsets With Sum K (Memoization)

class Solution {
public:
    int dfs(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(!i){
            if(!nums[0] and !j) return 2;
            if(!j) return 1;
            return nums[0] == j;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int notPick = dfs(i-1,j,nums,dp);
        int pick = nums[i]<=j ? dfs(i-1,j-nums[i], nums, dp) : 0;
    return dp[i][j]=pick+notPick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum=accumulate(nums.begin(), nums.end(), 0);
        int n=nums.size();
        if((target+total_sum)%2 or target>total_sum or target<-total_sum){
            return 0;
        }
        int t=(total_sum+target)/2;
        vector<vector<int>> dp(n,vector<int>(t+1, -1));

    return dfs(n-1,t,nums,dp);
    }
};


/// Approach 2: Tabulation

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i:nums)
            sum+=i;
        if((target+sum)&1 || abs(target)>sum)
            return 0;
        int t=(target+sum)/2;
        vector<int> dp(t+1);
        dp[0]=1;
        for(int i:nums)
        {
            for(int j=t;j>=i;j--)
            {
                if(dp[j-i])
                    dp[j]+=dp[j-i];
            }
        }
        return dp[t];
    }
};
