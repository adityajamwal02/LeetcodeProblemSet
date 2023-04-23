/*
Given an array A[] of positive integers. The task is to complete the function which returns an integer denoting the minimum sum subsequence from the array such that at least one value among all groups of four consecutive elements is picked.
Examples:

Input: A[] = {1, 2, 3, 4, 5, 6, 7, 8}
Output: 6
6 is sum of output subsequence {1, 5}
Following 4 length subarrays are possible
(1, 2, 3, 4), (2, 3, 4, 5), (3, 4, 5, 6),
(4, 5, 6, 7), (5, 6, 7, 8)
Here, Our subsequence {1, 5} has an element from all
above groups of four consecutive elements.

Input: A[] = {2, 1, 3}

Output: 1

The N (size of A) is less than 4, so the subsequnce is {1}.

Input: A[] = {1, 2, 3, 3, 4, 5, 6, 1}
Output: 4
The subsequence is {3, 1}. Here we consider
second three.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains an integer N. Then in the next line are N space separated values of the array A[].

Output:
For each test case in a new line output will be the min sum of such subsequence .

Constraints:
1<=T<=100
1<=N<=50
1<=A[]<=1000

Example(To be used only for expected output):
Input:
2
8
1 2 3 4 5 6 7 8
8
1 2 3 3 4 5 6 1
Output:
6
4
*/

/// Logical solution

/*You are required to complete below method */

class Solution{
    public:
    int minSum(int arr[], int n){
        if(n<=4){
            return *min_element(arr,arr+n);
        }
        int a,b,c,d,e;
        a=arr[0];
        b=arr[1];
        c=arr[2];
        d=arr[3];
        for(int i=4;i<n;i++){
            e=arr[i]+min({a,b,c,d});
            a=b;
            b=c;
            c=d;
            d=e;
        }
    return min({a,b,c,d,e});
    }
};
