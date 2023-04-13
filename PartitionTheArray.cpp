/*
Given an array A[] of N integers. The task is to partition the array into four non-empty contiguous subarrays P, Q, R, and S such that each element of the array A[] should be present in any subarray.
Let W, X, Y, and Z be the sum of the elements in P, Q, R, and S respectively.
Find the smallest absolute difference between the maximum and the minimum among W, X, Y, and Z.

Example 1:

Input:
N = 5
A[] = [4,2,2,5,1]
Output: 4
Explanation: let partition the array
P,Q,R,S = [4],[2,2],[5],[1]
W = 4, X = 4, Y = 5, Z = 1
Differnce = max(W,X,Y,Z)-min(W,X,Y,Z)= 5-1 = 4
Example 2:

Input:
N = 4
A[] = {4,4,4,4}
Output: 0
Explanation:
There is only one way to partition
the array. P,Q,R,S = [4],[4],[4],[4]
Your Task:
You don't need to read input or print anything. The task is to complete the function minDifference() which takes the integer N and the array A[] as inputs and returns the smallest absolute difference.

Expected Time Complexity: O(NLogN)
Expected Auxiliary Space: O(N)
*/

/// Binary Search


class Solution
{
public:
    vector<long> maxMin(vector<long>& prefixSum, int l, int h) {
    int low = l, high = h;
    long maxSum = LONG_MAX, minSum = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long leftSum = prefixSum[mid] - ((l - 1) >= 0 ? prefixSum[l - 1] : 0);
        long rightSum = prefixSum[h] - prefixSum[mid];

        if (abs(rightSum - leftSum) < maxSum - minSum) {
            maxSum = max(rightSum, leftSum);
            minSum = min(leftSum, rightSum);
        }

        if (leftSum < rightSum) low = mid + 1;
        else high = mid - 1;
    }

    return vector<long>{minSum, maxSum};
    }

    long minDifference(int N, vector<int>& A) {
        vector<long> prefixSum(N);

        prefixSum[0] = A[0];
        for (int i = 1; i < N; i++) {
            prefixSum[i] = prefixSum[i - 1] + A[i];
        }

        long ans = LONG_MAX;

        for (int i = 1; i < N - 2; i++) {
            vector<long> maxMinLeft = maxMin(prefixSum, 0, i);
            vector<long> maxMinRight = maxMin(prefixSum, i + 1, N - 1);

            long value = max(maxMinLeft[1], maxMinRight[1]) - min(maxMinLeft[0], maxMinRight[0]);
            ans = min(ans, value);
        }

        return ans;
    }
};
