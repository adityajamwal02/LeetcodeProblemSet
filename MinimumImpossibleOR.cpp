/*
You are given a 0-indexed integer array nums.
We say that an integer x is expressible from nums if there exist some integers 0 <= index1 < index2 < ... < indexk < nums.length for which nums[index1] | nums[index2] | ... | nums[indexk] = x. In other words, an integer is expressible if it can be written as the bitwise OR of some subsequence of nums.
Return the minimum positive non-zero integer that is not expressible from nums.

Example 1:
Input: nums = [2,1]
Output: 4
Explanation: 1 and 2 are already present in the array. We know that 3 is expressible, since nums[0] | nums[1] = 2 | 1 = 3. Since 4 is not expressible, we return 4.

Example 2:
Input: nums = [5,3,2]
Output: 1
Explanation: We can show that 1 is the smallest number that is not expressible.
*/

/// Sorting and Power of 2 ( O(nlogn) )

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int i=1, j=0;
        while(j<n){
            if(nums[j]>i){
                return i;
            }
            if(nums[j]==i){
                i=i*2;
            }
        j+=1;
        }
    return i;
    }
};

/// BitMap solution

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }
        for(int i=0;i<32;i++){
            if(!mp.count(1<<i)){
                return 1<<i;
            }
        }
    return 1<<32;
    }
};
