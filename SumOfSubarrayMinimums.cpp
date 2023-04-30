/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
*/

/// 2 Stack Forward and Backward Pass

class Solution {
public:
    int mod=1e9+7;

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<pair<int,int>> st1, st2;
        vector<int> left(n), right(n);
        // Forward Pass : Left -> right
        for(int i=0;i<n;i++){
            int counter=1;
            while(!st1.empty() and st1.top().first > arr[i]){
                counter+=st1.top().second;
                st1.pop();
            }
            st1.push({arr[i],counter});
            left[i]=counter;
        }
        // Backward Pass : Right -> Left
        for(int i=n-1;i>=0;i--){
            int counter=1;
            while(!st2.empty() and st2.top().first >= arr[i]){
                counter+=st2.top().second;
                st2.pop();
            }
            st2.push({arr[i],counter});
            right[i]=counter;
        }
        int result=0;
        for(int i=0;i<n;i++){
            result=(result+((long long)(arr[i]*left[i])%mod*right[i])%mod)%mod;
        }
    return result%mod;
    }
};
