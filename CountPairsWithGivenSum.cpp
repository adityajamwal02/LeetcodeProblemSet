/*
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

Example 1:
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation:
arr[0] + arr[1] = 1 + 5 = 6
and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:
Input:
N = 4, K = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation:
Each 1 will produce sum 2 with any 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function getPairsCount() which takes arr[], n and k as input parameters and returns the number of pairs that have sum K.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/


/// Map Approach o(n)

//User function template for C++

class Solution{
public:
    int getPairsCount(int arr[], int n, int k) {
        int counter=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp[arr[i]]!=0){
                int temp=mp[arr[i]];
                counter=counter+temp;
            }
            mp[k-arr[i]]++;
        }
    return counter;
    }
};


/// Brute Approach

class Solution {
    int getPairsCount(int[] arr, int n, int k) {
        // code here
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]+arr[j]==k)
                {
                    count++;
                }
            }
        }
        return count;
    }
}
