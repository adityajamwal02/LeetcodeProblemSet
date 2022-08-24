/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
*/

class Solution {
public:

    int firstocc(vector<int> &nums, int n, int target)
    {
        int low=0,high=n-1, ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else if(nums[mid]>target)
                high=mid-1;
        }
    return ans;
    }
    int lastocc(vector<int> &nums, int n, int target)
    {
        int low=0,high=n-1, ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else if(nums[mid]>target)
                high=mid-1;
        }
    return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstocc(nums, nums.size(), target), lastocc(nums, nums.size(), target)};
    }
};
