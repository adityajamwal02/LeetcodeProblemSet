/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

class Solution {
public:
    void solve(vector<int> &nums, vector<int> &ds, int index, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i=index;i<nums.size();i++){
            if(i!=index and nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(nums,ds,i+1,ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(nums,ds,0,ans);

    return ans;
    }
};
