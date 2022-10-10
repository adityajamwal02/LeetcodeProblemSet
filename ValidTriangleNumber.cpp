/*
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Example 2:
Input: nums = [4,2,3,4]
Output: 4
*/


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int k=i+2;
            for(int j=i+1;j<n-1 and nums[i]!=0;j++){
                while(k<n and nums[i]+nums[j]>nums[k])
                    k++;
                count+=k-j-1;
            }
        }
    return count;
    }
};
