class Solution {
public:
    vector<int> dp;
    int help(vector<int> &nums, int target, int n){
        if(target==0)
            return 1;
        int ans=0;

        if(dp[target]!=-1)
            return dp[target];

        for(int i=0;i<n;i++)
        {
            if(nums[i]<=target)
            {
                ans+=help(nums, target-nums[i], n);
            }
        }
    return dp[target]=ans;
    }


    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        dp.resize(target+1, -1);
        return help(nums, target, n);
    }
};
