/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int l=i+1, h=nums.size()-1;
            while(l<h){
                long long sum=nums[i]+nums[l]+nums[h];
                if(abs(target-sum)<abs(target-res)){
                    res=sum;
                }else if(sum>target)
                    h--;
                else
                    l++;
            }
        }
    return res;
    }
};
