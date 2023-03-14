/*
Given an array arr and target sum k, check whether there exists a subsequence such that the sum of all elements in the subsequence equals the given target sum(k).

Example:
Input:  arr = [10,1,2,7,6,1,5], k = 8.
Output:  Yes
Explanation:  Subsequences like [2, 6], [1, 7] sum upto 8

Input:  arr = [2,3,5,7,9], k = 100.
Output:  No
Explanation:  No subsequence can sum upto 100
Your Task:
You don't need to read or print anything. Your task is to complete the boolean function checkSubsequenceSum() which takes N, arr and K as input parameter and returns true/false based on the whether any subsequence with sum K could be found.

Expected Time Complexity: O(N * K).
Expected Auxiliary Space: O(N * K).
*/

class Solution{
    public:
    bool helper(int i, vector<int> &arr, int n, int k, int sum){
        if(sum>k) return false;
        if(sum==k) return true;
        if(i==n){
            if(sum!=k) return false;
        }
        if(helper(i+1,arr,n,k,sum+arr[i])) return true;
        if(helper(i+1,arr,n,k,sum)) return true;
    return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        int sum=0;
        bool result = helper(0,arr,n,k,sum);
    return result;
    }
};
