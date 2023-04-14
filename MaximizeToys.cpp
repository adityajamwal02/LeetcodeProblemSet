/*
Given an array arr[ ] of length N consisting cost of N toys and an integer K depicting the amount with you. Your task is to find maximum number of toys you can buy with K amount.

Example 1:
Input:
N = 7
K = 50
arr[] = {1, 12, 5, 111, 200, 1000, 10}
Output: 4
Explaination: The costs of the toys
you can buy are 1, 12, 5 and 10.

Example 2:
Input:
N = 3
K = 100
arr[] = {20, 30, 50}
Output: 3
Explaination: You can buy all toys.
Your Task:
You do not need to read input or print anything. Your task is to complete the function toyCount() which takes the integer N, integer K and the array arr[ ] as input parameters and returns the maximum count of toys you can have.

Expected Time Complexity: O(N * Log(N))
Expected Auxiliary Space: O(1)

*/

//User function Template for C++

class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        sort(arr.begin(), arr.end());
        int counter=0;
        for(int i=0;i<N;i++){
            if(K<arr[i]) return counter;
            else{
                counter++;
                K=K-arr[i];
            }
        }
    return counter;
    }
};
