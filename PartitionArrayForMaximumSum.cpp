/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

Example 2:
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

Example 3:
Input: arr = [1], k = 1
Output: 1
*/

/// Recursion

class Solution {
public:

    int helper(int i, vector<int> &arr, int n, int k){
        if(i==n) return 0;
        int maxSum=INT_MIN, length=0;
        int sum=0, maxElement=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            length++;
            maxElement=max(maxElement,arr[j]);
            sum=(length*maxElement)+helper(j+1, arr, n, k);
            maxSum=max(sum, maxSum);
        }
    return maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
    return helper(0,arr,n,k);
    }
};


/// Memoization

class Solution {
public:

    int helper(int i, vector<int> &arr, int n, int k, vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxSum=INT_MIN, length=0;
        int sum=0, maxElement=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            length++;
            maxElement=max(maxElement,arr[j]);
            sum=(length*maxElement)+helper(j+1, arr, n, k, dp);
            maxSum=max(sum, maxSum);
        }
    return dp[i]=maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
    return helper(0,arr,n,k,dp);
    }
};

/// Tabulation

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        int maxSum=INT_MIN;
        for(int i=n-1;i>=0;i--){
            int length=0;
            int sum=0, maxElement=INT_MIN;
            for(int j=i;j<min(n,i+k);j++){
                length++;
                maxElement=max(maxElement,arr[j]);
                sum=(length*maxElement)+dp[j+1];
                maxSum=max(sum, maxSum);
                dp[i]=maxSum;
             }
        }

    return dp[0];
    }
};
