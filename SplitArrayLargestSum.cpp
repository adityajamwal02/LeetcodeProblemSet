/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
*/


/// Binary Search Solution

class Solution {
public:
    int split(vector<int> &nums, int largestSum){
        int pieces=1;
        int tempSum=0;
        for(auto it: nums){
            if(tempSum+it > largestSum){
                tempSum=it;
                pieces++;
            }else{
                tempSum+=it;
            }
        }
    return pieces;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxElement=*max_element(nums.begin(), nums.end());
        int sumTotal=accumulate(nums.begin(), nums.end(), 0);
        int low=maxElement, high=sumTotal;
        while(low<high){
            int mid=low+(high-low)/2;
            int pieces=split(nums,mid);
            if(pieces>k){
                low=mid+1;
            }else{
                high=mid;
            }
        }
    return low;
    }
};

