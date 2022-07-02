#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution{

public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            {
                mp[nums[i]]++;
                if(mp[nums[i]]>1)
                    return true;
            }
            return false;
        }
};

int main()
{
    vector<int> nums{1,2,3,2};
    Solution s;
    cout<<s.containsDuplicate(nums);
}
