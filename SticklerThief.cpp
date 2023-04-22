/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.

Example 1:
Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110

Example 2:
Input:
n = 3
a[] = {1,2,3}
Output: 4
Explanation: 1+3=4
Your Task:
Complete the functionFindMaxSum()which takes an array arr[] and n as input which returns the maximum money he can get following the rules

Expected Time Complexity:O(N).
Expected Space Complexity:O(N).

*/

/// Memoization

class Solution
{
    public:
    //Function to find the maximum money the thief can get.

    int helper(int i, int n, int arr[], vector<int> &dp){
        if(n==0) return 0;
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int Notpick=helper(i+1,n,arr,dp);
        int pick=max(helper(i+2,n,arr,dp)+arr[i], helper(i+1,n,arr,dp));

    return dp[i]=max(pick, Notpick);
    }

    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n+1,-1);
    return helper(0,n,arr,dp);
    }
};

/// Tabulation

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
