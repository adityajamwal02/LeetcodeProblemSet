/*
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            product=(nums[i]*product);
            maxi=max(maxi,product);
            if(product==0){
                product=1;
            }
        }
        product=1;
        for(int i=nums.size()-1;i>=0;i--){
            product=product*nums[i];
            maxi=max(product,maxi);
            if(product==0){
                product=1;
            }
        }
    return maxi;
    }
};
