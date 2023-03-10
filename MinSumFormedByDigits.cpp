/*
Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array. All digits of the given array must be used to form the two numbers.
Any combination of digits may be used to form the two numbers to be summed.  Leading zeroes are permitted.
If forming two numbers is impossible (i.e. when n==0) then the "sum" is the value of the only number that can be formed.

Example 1:

Input:
N = 6
arr[] = {6, 8, 4, 5, 2, 3}
Output:
604
Explanation:
The minimum sum is formed by numbers
358 and 246


Example 2:

Input:
N = 5
arr[] = {5, 3, 0, 7, 4}
Output:
82
Explanation:
The minimum sum is formed by numbers
35 and 047


Your Task:
You don't have to print anything, printing is done by the driver code itself. Your task is to complete the function minSum() which takes the array A[] and its size N as inputs and returns the required sum.

Expected Time Complexity: O(N. log(N))
Expected Auxiliary Space: O(N)
*/


class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        if(n==0) return 0;
        if(n==1) return arr[0];
        sort(arr,arr+n);
        long long int a=0, b=0;
         for(int i=0;i<n;i=i+2)
        {
          a=a*10+arr[i];
          if(i+1==n)break;
          b=b*10+arr[i+1];
        }
    return a+b;
    }
};
