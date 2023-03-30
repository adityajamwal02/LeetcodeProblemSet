/*
Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.

Example 1:
Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.

Example 2:
Input: nums = [0], lower = 0, upper = 0
Output: 1
*/

/// Merge Sort Approach

class Solution {
public:

    long long low,high;
    int ans;
    int n;
    vector<long long> arr;
    vector<int> nums;
    void mergeSort(int l,int r)
    {
        if(l == r)
        {
            return;
        }
        int mid = (l+r)/2;
        mergeSort(l,mid);
        mergeSort(mid+1,r);

        int ans = 0;
        for(int i = mid+1;i<=r;i++)
        {
            long long left = arr[i] - high,right = arr[i]-low;
            int gap = (upper_bound(arr.begin()+l,arr.begin()+mid+1,right) - lower_bound(arr.begin()+l,arr.begin()+mid+1,left));
            if(i == mid+1)
            {
                int temp = nums[i];
                if(temp<=high && temp>=low)
                    gap--;
            }
            if(l == 0)
            {
                if((arr[i])<=high && arr[i]>=low)
                {
                    gap++;
                }
            }
            ans += gap;
        }
        this->ans += ans;
        sort(arr.begin()+l,arr.begin()+r+1);

    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int sum = 0;
        this->low = lower,this->high = upper;
        this->nums = nums;
        n = nums.size();
        arr = vector<long long>(n);
        arr[0] = nums[0];
        for(auto &x:nums)
        {
            if(x<=upper && x>=lower)
                ans++;
        }
        for(int i = 1;i<n;i++)
            arr[i] = arr[i-1]+nums[i];
        mergeSort(0,n-1);
        return ans;

    }
};
