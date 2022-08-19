/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/

/// Set Approach

class Solution{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> s;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                int csum=val+nums[l]+nums[r];
                if(csum==0){
                    s.insert({val, nums[l], nums[r]});
                    l++;r--;
                }
                else if(csum<0) l++;
                else r--;
            }
        }
    for(auto i : s)
        ans.push_back(i);

    return ans;
    }
};


/// 2 pointer approach only

class Solution {
public:
vector<vector<int>> threeSum(vector<int> &nums) {
vector<vector<int>> res;
sort(nums.begin(),nums.end());
for(int i=0;i<nums.size()-2;i++)
{
if(i==0 || (i>0 && nums[i]!=nums[i-1]))
{
int l=i+1,h=nums.size()-1,sum =0 - nums[i];

            while(l<h)
            {
                if(sum == nums[l]+nums[h])
                {
                    vector<int> temp(3);
                    temp[0]=nums[i];
                    temp[1]=nums[l];
                    temp[2]=nums[h];
                    res.push_back(temp);
                    while(l<h && nums[l]==nums[l+1])
                        l++;
                    while(l<h && nums[h]==nums[h-1])
                        h--;
                    l++;
                    h--;
                }
                else if(nums[l]+nums[h] <sum)
                    l++;
                else
                    h--;
            }
        }
    }
    return res;
}
};
