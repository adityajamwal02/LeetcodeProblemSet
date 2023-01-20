/*
Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

Example 1:
Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

Example 2:
Input: nums = [4,4,3,2,1]
Output: [[4,4]]
*/


class Solution {
    vector<vector<int>>ans;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>tmp;
        backtrack(nums , tmp , 0 , nums.size()-1);
        return ans;
    }
    void backtrack(vector<int>& nums , vector<int>& tmp  , int l , int r){
        if(tmp.size() > 1){
            ans.push_back(tmp);
        }
        unordered_set<int>h;
        for(int i = l ; i <= r ; i ++){
            if((tmp.empty() || nums[i] >= tmp.back()) && (h.find(nums[i]) == h.end()) ){
                tmp.push_back(nums[i]);
                backtrack(nums , tmp , i+1 , r);
                tmp.pop_back();
                h.insert(nums[i]);
            }

        }

    }
};
