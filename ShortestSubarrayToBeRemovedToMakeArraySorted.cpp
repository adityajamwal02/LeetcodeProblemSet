/*
Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
Return the length of the shortest subarray to remove.
A subarray is a contiguous subsequence of the array

Example 1:
Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].

Example 2:
Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].

Example 3:
Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any elements.
*/

/// Solution 1

class Solution {
public:
   int findLengthOfShortestSubarray(vector<int>& n)
    {
        int sz = n.size(), r = sz - 1;
        for (; r > 0 && n[r - 1] <= n[r]; --r) ;
        auto res = r;
        for (int l = 0; l < r && (l == 0 || n[l - 1] <= n[l]); ++l) {
            while (r < sz && n[r] < n[l])
                ++r;
            res = min(res, r - l - 1);
        }
        return res;
    }
};


/// Solution 2

class Solution {
public:
   int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int size=arr.size();
        int r;
        for(r=size-1;r>=1;r--){
            if(arr[r-1]>arr[r]){
                break;
            }
        }
        int ans=r;
        for(int i=0;i<size-1 and i<r;i++){
            if (r == size or arr[i]<=arr[r]){
                ans=min(ans, r-i-1);
            }else{
                r++;
            }
            if(arr[i+1]<arr[i]) break;
        }
    return ans;
    }
};
