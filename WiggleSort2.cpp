/*
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]...
You may assume the input array always has a valid answer.

Example 1:
Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.

Example 2:
Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]
*/


/// O(nlogn) solution

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result(nums.size(), 0);
        result=nums;
        int j=nums.size()-1;
        for(int i=1;i<nums.size();i+=2){
            result[i]=nums[j];
            j--;
        }
        for(int i=0;i<nums.size();i+=2){
            result[i]=nums[j];
            j--;
        }
    nums=result;
    }
};
