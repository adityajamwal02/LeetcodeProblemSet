/*
Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.

Example 1:
Input: nums1 = [4,1,3], nums2 = [5,7]
Output: 15
Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.

Example 2:
Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
Output: 3
Explanation: The number 3 contains the digit 3 which exists in both arrays.
*/

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        map<int,int> mp;
        for(auto num : nums1){
            mp[num]++;
        }
        for(auto num : nums2){
            mp[num]++;
        }
        for(auto it : mp){
            if(it.second>=2){
                return it.first;
            }
        }
        string temp1 = to_string(nums1[0]);
        string temp2 = to_string(nums2[0]);
        string result1 = temp1+temp2;
        string result2 = temp2+temp1;
        int ans1 = stoi(result1);
        int ans2 = stoi(result2);
        if(ans1>ans2) return ans2;

    return ans1;
    }
};
