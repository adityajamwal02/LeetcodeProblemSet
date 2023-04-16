/*
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key. The task is to find the index of the given element key in the array A. The whole array A is given as the range to search.

Example 1:
Input:
N = 9
A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}
key = 10
l = 0 , h = 8
Output:
5
Explanation: 10 is found at index 5.

Example 2:
Input:
N = 4
A[] = {3, 5, 1, 2}
key = 6
l = 0 , h = 3
Output:
-1
Explanation: There is no element that has value 6.
Your Task:
Complete the function search() which takes an array arr[] and start, end index of the array and the K as input parameters, and returns the answer.

Can you solve it in expected time complexity?

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).
*/


class Solution{
    public:
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        while(l<=h){
            int mid=l+(h-l)/2;
            if(A[mid]==key) return mid;
            if(A[l]<=A[mid]){
                if(A[l]<=key and key<=A[mid]){
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                if(A[mid]<=key and key<=A[h]){
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
        }
    return -1;
    }
};
