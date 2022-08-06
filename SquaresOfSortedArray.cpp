/*
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
*/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i]=pow(nums[i],2);
        }
        sort(nums.begin(), nums.end());

    return nums;
    }
};
