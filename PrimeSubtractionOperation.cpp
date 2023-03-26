/*
You are given a 0-indexed integer array nums of length n.
You can perform the following operation as many times as you want:
Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
Return true if you can make nums a strictly increasing array using the above operation and false otherwise.
A strictly increasing array is an array whose each element is strictly greater than its preceding element.

Example 1:
Input: nums = [4,9,6,10]
Output: true
Explanation: In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
After the second operation, nums is sorted in strictly increasing order, so the answer is true.

Example 2:
Input: nums = [6,8,11,12]
Output: true
Explanation: Initially nums is sorted in strictly increasing order, so we don't need to make any operations.

Example 3:
Input: nums = [5,8,3]
Output: false
Explanation: It can be proven that there is no way to perform operations to make nums sorted in strictly increasing order, so the answer is false.
*/

class Solution {
public:
    vector<int> pr;
    void sieve(int n)
    {
        vector<bool> prime(n+1,true);

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        for (int p = 2; p <= n; p++)
            if (prime[p])
                pr.push_back(p);
    }


    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        sieve(1010);

        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] >= nums[i+1])
            {
                for(int j : pr)
                {
                    if(j >= nums[i])
                        break;

                    if(nums[i]-j < nums[i+1])
                    {
                        nums[i] -= j;
                        break;
                    }
                }
            }

            if(nums[i] >= nums[i+1])
                return false;
        }

        return true;
    }
};
