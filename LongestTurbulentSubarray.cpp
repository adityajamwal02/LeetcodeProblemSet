/*
Given an integer array arr, return the length of a maximum size turbulent subarray of arr.
A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:
For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.

Example 1:
Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]

Example 2:
Input: arr = [4,8,12,16]
Output: 2

Example 3:
Input: arr = [100]
Output: 1
*/

/// Sliding Window Solution

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size(), i=0, j=0, result=1;
        bool flag=1;
        while(j+1<n){
            if((arr[j]>arr[j+1] and flag==1) or (arr[j]<arr[j+1] and flag==0)){
                flag=!flag;
                result=max(result,j-i+2);
                j++;
            }else if((arr[j]<arr[j+1] and flag==1) or (arr[j]>arr[j+1] and flag==0)){
                flag=!flag;
                i=j;
            }else{
                j++;
                i=j;
            }
        }
    return result;
    }
};

/// DP solution

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        int result=1;
        if(n==1) return 1;
        vector<int> inc(n,1), dec(n,1);
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                dec[i]=inc[i-1]+1;
            }else if(arr[i]>arr[i-1]){
                inc[i]=dec[i-1]+1;
            }else{
                continue;
            }
        }
        for(int i=0;i<n;i++){
            result=max({result,inc[i],dec[i]});
        }
    return result;
    }
};
