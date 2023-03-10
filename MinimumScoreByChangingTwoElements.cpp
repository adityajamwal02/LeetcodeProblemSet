/*
You are given a 0-indexed integer array nums.
The low score of nums is the minimum value of |nums[i] - nums[j]| over all 0 <= i < j < nums.length.
The high score of nums is the maximum value of |nums[i] - nums[j]| over all 0 <= i < j < nums.length.
The score of nums is the sum of the high and low scores of nums.
To minimize the score of nums, we can change the value of at most two elements of nums.
Return the minimum possible score after changing the value of at most two elements of nums.
Note that |x| denotes the absolute value of x.

Example 1:
Input: nums = [1,4,3]
Output: 0
Explanation: Change value of nums[1] and nums[2] to 1 so that nums becomes [1,1,1]. Now, the value of |nums[i] - nums[j]| is always equal to 0, so we return 0 + 0 = 0.

Example 2:
Input: nums = [1,4,7,8,5]
Output: 3
Explanation: Change nums[0] and nums[1] to be 6. Now nums becomes [6,6,7,8,5].
Our low score is achieved when i = 0 and j = 1, in which case |nums[i] - nums[j]| = |6 - 6| = 0.
Our high score is achieved when i = 3 and j = 4, in which case |nums[i] - nums[j]| = |8 - 5| = 3.
The sum of our high and low score is 3, which we can prove to be minimal.
*/

/// Sorting

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int choice1 = abs(nums[n-1]-nums[2]);
        int choice2 = abs(nums[1]-nums[n-2]);
        int choice3 = abs(nums[0]-nums[n-3]);
    return min(choice1, min(choice2, choice3));

    }
};

/// Without sorting

/*
After sorting the order of the variables are as follows :
s1, s2, s3 ......... l3, l2, l1
s1 is smallest & l1 is largest.
*/

    int minimizeSum(vector<int>& nums) {
        int s1 = INT_MAX, s2 = INT_MAX, s3 = INT_MAX, l1 = 0, l2 = 0, l3 = 0;
        for(auto n: nums){
            if(s1 > n) { s3 = s2; s2 = s1; s1 = n; }
            else if(s2 > n) { s3 = s2; s2 = n; }
            else if(s3 > n) { s3 = n; }

            if(l1 < n) { l3 = l2; l2  = l1; l1 = n; }
            else if(l2 < n ) { l3 = l2; l2 = n; }
            else if(l3 < n ) { l3 = n; }
        }
        return min({l1 - s3, l3 - s1, l2 - s2});
    }
