/*
You are given an integer array nums and two integers indexDiff and valueDiff.
Find a pair of indices (i, j) such that:
i != j,
abs(i - j) <= indexDiff.
abs(nums[i] - nums[j]) <= valueDiff, and
Return true if such pair exists or false otherwise.

Example 1:
Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
Output: true
Explanation: We can choose (i, j) = (0, 3).
We satisfy the three conditions:
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0

Example 2:
Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
Output: false
Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
*/


/// Brute Force

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i!=j and abs(i-j)<=indexDiff and abs(nums[i]-nums[j])<=valueDiff){
                    return true;
                    break;
                }
            }
        }
    return false;
    }
};


///  Sorting Method

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<pair<long, long>> arr(nums.size());
        for(int i=0;i<nums.size();i++){
            arr[i].first=nums[i];
            arr[i].second=i;
        }
        sort(arr.begin(), arr.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(arr[i].first+valueDiff>=arr[j].first)){
                    if(abs(arr[i].second-arr[j].second)<=indexDiff){
                        return true;
                    }
                }else{
                    break;
                }
            }
        }
    return false;
    }
};

/// Multiset and Sliding window

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        int n = nums.size();
        multiset<int> ms;     //to store window elements in sorted order

		int i=0, j=0;
        while(j<n)
        {
            auto up = ms.upper_bound(nums[j]);
            if((up != ms.end() and *up-nums[j] <= t) || (up != ms.begin() and nums[j] - *(--up) <= t))
                return true;
            ms.insert(nums[j]);

            if(ms.size() == k+1)
            {
                ms.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};
