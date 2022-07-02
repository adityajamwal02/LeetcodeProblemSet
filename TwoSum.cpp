#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
                return {i, mp[target-nums[i]]};
            mp[nums[i]]=i;
        }
        return {};
}
};

int main()
{
    Solution s;
    vector<int>nums{2,3,4,5,7};
    int target=10;
    cout<<s.twoSum(nums, 10);

    return 0;
}
