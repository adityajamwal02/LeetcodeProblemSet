/*
You are given two positive integer arrays nums and target, of the same length.
In one operation, you can choose any two distinct indices i and j where 0 <= i, j < nums.length and:
set nums[i] = nums[i] + 2 and
set nums[j] = nums[j] - 2.
Two arrays are considered to be similar if the frequency of each element is the same
Return the minimum number of operations required to make nums similar to target. The test cases are generated such that nums can always be similar to target.

Example 1:
Input: nums = [8,12,6], target = [2,14,10]
Output: 2
Explanation: It is possible to make nums similar to target in two operations:
- Choose i = 0 and j = 2, nums = [10,12,4].
- Choose i = 1 and j = 2, nums = [10,14,2].
It can be shown that 2 is the minimum number of operations needed.

Example 2:
Input: nums = [1,2,5], target = [4,1,3]
Output: 1
Explanation: We can make nums similar to target in one operation:
- Choose i = 1 and j = 2, nums = [1,4,3].

Example 3:
Input: nums = [1,1,1,1,1], target = [1,1,1,1,1]
Output: 0
Explanation: The array nums is already similiar to target.
*/

/// Short Precise

class Solution {
public:
    static bool comp(int &A, int &B) {
        return (A&1)<(B&1) or ((A&1)==(B&1) and A<B);
    }
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end(), comp);
        sort(target.begin(), target.end(), comp);
        long long counter=0, n=nums.size();
        for(int i=0;i<n;i++){
            counter+=abs(nums[i]-target[i]);
        }
    return counter>>2;
    }
};

/// Longer

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector <int> even,odd;
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2){
                odd.push_back(nums[i]);
            }
            else{
                even.push_back(nums[i]);
            }
        }
        long long i=0,j=0;
        long long inc=0,dec=0;
        for(int k=0;k<target.size();k++){
            long long d;
            if(target[k]%2){
                d=1LL*odd[j++]-target[k];
            }
            else{
                d=1LL*even[i++]-target[k];
            }
            if(d<0){
                inc+=abs(d/2);
            }
            else{
                dec+=abs(d/2);
            }
        }
        long long ans=min(inc,dec)+(abs(inc-dec)/2);
        return ans;
    }
};
