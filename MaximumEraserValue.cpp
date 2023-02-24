/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
Return the maximum score you can get by erasing exactly one subarray.
An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

Example 1:
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
*/

/// Sliding Window + Map

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(), i=0, j=0;
        unordered_map<int,int> mp;
        int result=0, currSum=0;
        while(i<n){
            if(mp[nums[i]]==0){
                currSum+=nums[i];
                mp[nums[i]]++;
                i++;
            }else{
                result=max(result,currSum);
                while(j<i and mp[nums[i]]==1){
                    currSum-=nums[j];
                    mp[nums[j]]--;
                    j++;
                }
            }
        }
    return max(result, currSum);
    }
};

/// Set Solution

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int curr_sum=0, res=0;

		//set to store the elements
        unordered_set<int> st;

        int i=0,j=0;
        while(j<nums.size()) {
            while(st.count(nums[j])>0) {
				//Removing the ith element untill we reach the repeating element
                st.erase(nums[i]);
                curr_sum-=nums[i];
                i++;
            }
			//Add the current element to set and curr_sum value
            curr_sum+=nums[j];
            st.insert(nums[j++]);

			//res variable to keep track of largest curr_sum encountered till now...
            res = max(res, curr_sum);
        }

        return res;
    }
};
