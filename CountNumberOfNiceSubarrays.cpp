/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.

Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.

Example 3:
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/

/// Sliding Window + 2 pointers

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size(), odd=0, counter=0, prefix=0;
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]%2!=0){
                odd++;
                prefix=0;
            }
            while(odd==k and i<=j){
                if(nums[i]%2!=0){
                    odd--;
                }
                prefix++; i++;
            }
        counter=counter+prefix;
        }
    return counter;
    }
};


/// Prefix Sum Approach

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Even -> 0 and Odd -> 1
        int n=nums.size();
        long long counter=0, prefixSum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }else{
                nums[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            mp[prefixSum]++;
            counter+=mp[prefixSum-k];
        }
    return counter;
    }
};
