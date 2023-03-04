/*
You are given an integer array nums and two integers minK and maxK.
A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

Example 2:
Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
*/

/// 2 pointers

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long n=nums.size();
        long long counter=0, max_index=-1, min_index=-1, last_index=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<minK or nums[i]>maxK){
                last_index=i;
                min_index=-1; max_index=-1;
            }else{
                if(nums[i]==minK) min_index=i;
                if(nums[i]==maxK) max_index=i;
                if(min_index!=-1 and max_index!=-1){
                    counter+=min(min_index,max_index)-last_index;
                }
            }
        }
    return counter;
    }
};
