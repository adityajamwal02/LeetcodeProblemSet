/*
Given an unsorted integer array nums, return the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space.
Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0 and nums[i]<=nums.size() and nums[nums[i]-1]!=nums[i])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)
                return i+1;
        }
    return nums.size()+1;
    }
};
