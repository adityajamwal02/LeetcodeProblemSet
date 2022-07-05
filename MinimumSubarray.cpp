#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int minSubArray(vector<int>& nums)
    {
        int minsum=nums[0];
        int currsum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(currsum>0)
                currsum=0;
            currsum+=nums[i];
            minsum=min(minsum, currsum);
        }
        return minsum;
    }
};

int main()
{
    Solution s;
    vector<int> nums{-2,1,-1,-10,4,-6,-1,8,3,-2,-8};
    cout<<s.minSubArray(nums);

    return 0;
}
