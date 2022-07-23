// Bottom Up Approach: Tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
            return nums[0];

        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);

        for(int i=2;i<n;i++)
        {
            dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
        }

    return dp[n-1];
    }
};

// Top Bottom Approach Memoization

class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n-1, dp);
    }

    int solve(vector<int>& nums, int index, vector<int>& dp)
    {
        if(index < 0)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        // Recurrence relation
        return dp[index] = max((nums[index] + solve(nums, index-2, dp)), solve(nums, index-1, dp));
    }
};

