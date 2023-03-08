/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/


/// Best Solution

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(auto a : arr)
            if(a<=k)
                k++;
    return k;
    }
};

/// Logn Binary Search Solution

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start=0, end= arr.size();
        while(start<end){
            int mid = (start+end)/2;
            if (arr[mid] - (mid+1) < k){
                start=mid+1;
            }else{
                end = mid;
            }
        }
        return start+k;
    }
};
