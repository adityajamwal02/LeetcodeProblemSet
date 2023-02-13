/*
The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

Example 1:
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Example 2:
Input: nums = [1,1,1], k = 2
Output: 0

Example 3:
Input: nums = [1,6,1], k = 3
Output: 5
*/

/// PQ Solution (TLE)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int N = nums.size();
        priority_queue<int> pq;
        int sum;
        for (int i = 0; i < N - 1; i++) {
		    for (int j = i + 1; j < N; j++) {
                sum = abs(nums[i] - nums[j]);
            	if (pq.size() == k) {
                    if (pq.top() > sum) {
                        pq.pop();
                        pq.push(sum);
                    }
                }
                else
                    pq.push(sum);
            }
	    }
    return pq.top();
    }
};

/// Binary search and Sliding window

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int start=0;
        int end=nums[n-1]-nums[0];
        while(start<=end){
            int  mid=start+(end-start)/2;
            int count=0, s=0, e=0;
            while(e<n){
                while(nums[e]-nums[s] > mid and s<n) s++;
                count+=(e-s);
                e++;
            }
            if(count>=k) end=mid-1;
            else start=mid+1;
        }
    return start;
    }
};
