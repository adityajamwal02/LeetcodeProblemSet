/*
Given an array A of n positive numbers. The task is to find the first Equilibrium Point in an array.
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
Note: Retun the index of Equilibrium point. (1-based index)

Example 1:
Input:
n = 5
A[] = {1,3,5,2,2}
Output: 3
Explanation:
equilibrium point is at position 3
as elements before it (1+3) =
elements after it (2+2).

Example 2:
Input:
n = 1
A[] = {1}
Output: 1
Explanation:
Since its the only element hence
its the only equilibrium point.

Your Task:
The task is to complete the function equilibriumPoint() which takes the array and n as input parameters and returns the point of equilibrium. Return -1 if no such point exists.
Expected Time Complexity: O(n)
*/


class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if(n==1){
            return 1;
        }
        long long prefix[n], suffix[n];
        prefix[0]=a[0];
        suffix[n-1]=a[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+a[i];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+a[i];
        }
        for(int i=1;i<n;i++){
            if(prefix[i]==suffix[i]){
                return i+1;
            }
        }

    return -1;
    }

};
