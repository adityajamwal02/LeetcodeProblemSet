#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

        int maxsum=nums[0];
        int currsum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(currsum<0)
                currsum=0;
            currsum+=nums[i];
            maxsum=max(maxsum, currsum);
        }
        return maxsum;
    }
};

int main()
{
    Solution s;
    vector<int> nums{-2,1,-1,4,2,5,-1,4,-8,7};
    cout<<s.maxSubArray(nums);

    return 0;
}
