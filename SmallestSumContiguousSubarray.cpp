/*
Given an array arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the minimum sum and return its sum.

Example 1:

Input:
arr[] = {3,-4, 2,-3,-1, 7,-5}
Output: -6
Explanation: sub-array which has smallest
sum among all the sub-array is {-4,2,-3,-1} = -6
Example 2:

Input:
arr[] = {2, 6, 8, 1, 4}
Output: 1
Explanation: sub-array which has smallest
sum among all the sub-array is {1} = 1
Your Task:
You don't need to read input or print anything. The task is to complete the function smallestSubarraySum() which takes arr[] and N as input parameters and returns the sum of subarray with minimum sum.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 106
-107 ≤ A[i] ≤ 107
*/

/// Normally

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      int n=a.size(), result=a[0], currsum=0;
      for(auto it : a){
          currsum=min(currsum+it , it);
          result=min(result,currsum);
      }
     return result;
  }
};


/// Reverse Kadane

class Solution{
  public:
    int smallestSumSubarray(vector<int>& arr){
        int n = arr.size(), curr=INT_MAX, mn=INT_MAX;
        for(int i=0; i<n; i++){
            curr = (curr>0)? arr[i] : curr+arr[i];
            mn = min(mn, curr);
        }

        return mn;
    }
};
