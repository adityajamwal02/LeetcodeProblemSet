/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array

Example 1:
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

Example 2:
Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
*/

/// Two Stack Solution

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
       stack<int> inc,dec;
       long result=0;
       for(int i=0;i<=nums.size();i++){
           while(!inc.empty() and (i==nums.size() or nums[inc.top()]<nums[i])){
               int curr=inc.top();
               inc.pop();
               int leftBound=inc.empty() ? -1 : inc.top();
               int rightBound=i;
               result+=(curr-leftBound)*(rightBound-curr)*(long)nums[curr];
           }
           while(!dec.empty() and (i==nums.size() or nums[dec.top()]>nums[i])){
               int curr=dec.top();
               dec.pop();
               int leftBound=dec.empty() ? -1 : dec.top();
               int rightBound=i;
               result-=(curr-leftBound)*(rightBound-curr)*(long)nums[curr];
           }
           inc.push(i);
           dec.push(i);
       }
    return result;
    }
};
