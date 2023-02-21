/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
*/

/// Backtracking (Recursion)

class Solution {
public:
    vector<int> result;
    void helper(int i, vector<int> &nums, vector<int> &ans){
        if(i==nums.size()){
            if(ans.size()>result.size()){
                result=ans;
            }
            return;
        }
        if(ans.size()==0){
            ans.push_back(nums[i]);
            helper(i+1,nums,ans);
            ans.pop_back();
        }else if(nums[i]%ans.back()==0){
            ans.push_back(nums[i]);
            helper(i+1,nums,ans);
            ans.pop_back();
        }
        helper(i+1,nums,ans);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        helper(0,nums,ans);
    return result;
    }
};


/// Memoization

class Solution {
public:
    vector<int> ans;
    void helper(int i,vector<int>& nums,vector<int>& vec,vector<int>& dp){
        if(i==nums.size()){
            if(vec.size()>ans.size())
                ans=vec;
            return;
        }
        if(vec.size()==0){
            vec.push_back(nums[i]);
            helper(i+1,nums,vec,dp);
            vec.pop_back();
        }
        else if((int)vec.size()>dp[i] && nums[i]%vec.back()==0){
            dp[i]=vec.size();
            vec.push_back(nums[i]);
            helper(i+1,nums,vec,dp);
            vec.pop_back();
        }
        helper(i+1,nums,vec,dp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> vec;
        vector<int> dp(nums.size()+1,-1);
        sort(nums.begin(),nums.end());
        helper(0,nums,vec,dp);
        return ans;
    }
};
