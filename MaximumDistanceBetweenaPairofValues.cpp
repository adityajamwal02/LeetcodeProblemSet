/*
You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.
A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.
Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.
An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length

Example 1:
Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
Output: 2
Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
The maximum distance is 2 with pair (2,4).

Example 2:
Input: nums1 = [2,2,2], nums2 = [10,10,1]
Output: 1
Explanation: The valid pairs are (0,0), (0,1), and (1,1).
The maximum distance is 1 with pair (0,1).
*/

/// Brute Solution

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int temp=0, dist=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                dist=0;
                if(nums1[i]<=nums2[j])
                    dist=j-i;
                temp=max(dist,temp);
               }
        }
    return temp;
    }
};


/// Two Pointer

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int temp=0, l=0, r=0;
        while(l<n and r<m){
            if(nums1[l]>nums2[r])
                l++;
            else{
                temp=max(temp,r-l);
                r++;
            }
        }
    return temp;
    }
};

/// Binary Solution

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = int(nums1.size()), n = int(nums2.size());
        int ans = 0;

        // Iterate over nums1 and find insertion position to nums2.
        for (int i = 0; i < m; ++i) {
            int k = nums2.rend() - lower_bound(nums2.rbegin(), nums2.rend(), nums1[i]);
            if (k > 0) {
                ans = max(ans, k - i - 1);
            }
        }

        return ans;
    }
};
