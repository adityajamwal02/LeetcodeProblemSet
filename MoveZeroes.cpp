/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         for(int NonZeroPos=0, curr=0;curr<nums.size();curr++) {
            if(nums[curr]!=0)
                swap(nums[NonZeroPos++], nums[curr]);
        }
    }
};
