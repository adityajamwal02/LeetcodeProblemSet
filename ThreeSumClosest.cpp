/*
Given an array, Arr of N numbers, and another number target, find three integers in the array such that the sum is closest to the target. Return the sum of the three integers.
Note: If there are multiple solutions, print the maximum one.

Example 1:
Input:
N = 6, target = 2
A[] = {-7,9,8,3,1,1}
Output: 2
Explanation: There is one triplet with sum
2 in the array. Triplet elements are -7,8,
1 whose sum is 2.

Example 2:
Input:
N = 4, target = 13
A[] = {5,2,7,5}
Output: 14
Explanation: There is one triplet with sum
12 and other with sum 14 in the array.
Triplet elements are 5, 2, 5 and 2, 7, 5
respectively. Since abs(13-12) ==
abs(13-14) maximum triplet sum will be
preferred i.e 14.
Your Task:
Complete threeSumClosest() function and return the expected answer.

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(1).
*/


int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int n= arr.size();
        int minsum = INT_MAX;
        sort(arr.begin(),arr.end());
        int ans =0;
        for(int i=0;i<n;i++){
            int first = arr[i];
            int start = i+1;
            int end = n-1;
                while(start < end){
                    int sum = first+arr[start]+arr[end];
                    if(sum==target) return sum;
                    if(abs(target-sum)<abs(target-minsum))
                        minsum = sum;
                    if(abs(target-sum)==abs(target-minsum))
                        minsum = max(sum,minsum);
                    if(sum>target) end--;
                    else start++;
                }
        }
        return minsum;
