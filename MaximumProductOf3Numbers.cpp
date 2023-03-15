/*
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6

Example 2:
Input: nums = [1,2,3,4]
Output: 24

Example 3:
Input: nums = [-1,-2,-3]
Output: -6

*/

/// Sorting

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        int first = nums[0]*nums[1]*nums[2];
        int second = nums[0]*nums[n-1]*nums[n-2];
    return max(first,second);
    }
};

/// O(n) solution

class Solution {
public:
    int maximumProduct(vector<int>& nums)
{
 int n = nums.size();
    int mx[3] = {-1001,-1001,-1001};
    int mn[2] = {1001,1001};
    int first, sec;
    for (int i = 0;i<n;i++)
    {
        if (nums[i] >= mx[0])
        {
            first = mx[0];
            sec = mx[1];
            mx[0]= nums[i];
            mx[1]=first;
            mx[2]=sec;
        }
        else if (nums[i] >= mx[1])
        {
            first = mx[1];
            mx[1]= nums[i];
            mx[2]=first;

        }
        else if (nums[i]> mx[2])
        {
            mx[2] = nums[i];
        }
        if (nums[i]<=mn[0])
        {
            first = mn[0];
            mn[0]=nums[i];
            mn[1]=first;
        }
        else if(nums[i]<=mn[1])
        {
            mn[1]=nums[i];
        }
    }
    return max(mn[0]*mn[1]*mx[0],mx[0]*mx[1]*mx[2]);
}
