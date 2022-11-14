/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array
such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

/// Basic TLE

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j] and abs(i-j)<=k)
                    return true;
            }
        }
    return false;
    }
};

/// Optimized Approach

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]]=i;
            else{
                auto x = (mp.find(nums[i]));
                int y=i;
                if(abs(x->second-y)<=k)
                    return true;
                else
                    mp[nums[i]]=i;
            }
        }
        return false;
    }
};
