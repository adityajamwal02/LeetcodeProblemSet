/*
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.

Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Example 1:

Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is
{4, 45, 6}

Example 2:
Input:
A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Explanation:
Minimum length subarray is {10}
*/


class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int i=0, sum=0, result=INT_MAX;
        for(int j=0;j<n;j++){
            sum+=arr[j];
            while(sum>x){
                result=min(result,j-i+1);
                sum-=arr[i];
                i++;
            }
        }
    return (result==INT_MAX) ? 0 : result;
    }
};
