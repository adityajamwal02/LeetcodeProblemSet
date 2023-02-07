/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such
that the sum of elements in both subsets is equal.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/

class Solution {
public:
    bool helper(vector<int> &nums, int k){
        vector<bool> prev(k+1,0), curr(k+1,0);
        prev[0]=curr[0]=true;
        if(nums[0]<=k)
            prev[nums[0]]=true;
        for(int index=1;index<nums.size();index++){
            for(int target=1;target<=k;target++){
                bool notTake=prev[target];
                bool take=false;
                if(nums[index]<=target)
                    take=prev[target-nums[index]];
                curr[target]=take|notTake;
            }
        prev=curr;
        }
    return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++)
            totalSum+=nums[i];
        if(totalSum&1)
            return false;

        int target=totalSum/2;

    return helper(nums,target);
    }
};
