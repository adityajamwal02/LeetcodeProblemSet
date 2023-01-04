/*
You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:
nums.length == n
nums[i] is a positive integer where 0 <= i < n.
abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
The sum of all the elements of nums does not exceed maxSum.
nums[index] is maximized.
Return nums[index] of the constructed array.
Note that abs(x) equals x if x >= 0, and -x otherwise.

Example 1:
Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

Example 2:
Input: n = 6, index = 1,  maxSum = 10
Output: 3
*/

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int right=n-index-1;
        int left=index;
        int low=1, high=maxSum, res=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            long sum=0, leftsum=0, righsum=0, m=mid-1;
            if(right<=m){
                righsum=m*(m+1)/2 - (m-right)*(m-right+1)/2;
            }else{
                righsum=m*(m+1)/2+right-m;
            }
            if(left<=m){
                leftsum=m*(m+1)/2 - (m-left)*(m-left+1)/2;
            }else{
                leftsum=m*(m+1)/2+left-m;
            }
            sum=mid+leftsum+righsum;
            if(sum<=maxSum)
                res=mid, low=mid+1;
            else high=mid-1;
        }
    return res;
    }
};

