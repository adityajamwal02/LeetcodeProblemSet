/*
Given an unsorted array arr[] of n positive integers. Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles.

Example 1:

Input:
n = 3
arr[] = {3, 5, 4}
Output:
1
Explanation:
A triangle is possible
with all the elements 5, 3 and 4.
Example 2:

Input:
n = 5
arr[] = {6, 4, 9, 7, 8}
Output:
10
Explanation:
There are 10 triangles
possible  with the given elements like
(6,4,9), (6,7,8),...


Your Task:
This is a function problem. You only need to complete the function findNumberOfTriangles() that takes arr[] and n as input parameters and returns the count of total possible triangles.

Expected Time Complexity: O(n2).
Expected Space Complexity: O(1).
*/


/// cube complexity

class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        int counter=0;
        sort(arr,arr+n);
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]+arr[j]>arr[k]){
                        counter++;
                    }else{
                        break;
                    }
                }
            }
        }
    return counter;
    }
};

/// Square Complexity

int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        sort(arr,arr+n);
        int cnt=0;
        for(int i=n-1;i>=2;i--){
            int c=arr[i];
            int start=0,end=i-1;
            while(end>start){
                if(arr[end]+arr[start]>c){
                    cnt+=(end-start);
                    end--;
                }
                else start++;
            }
        }
        return cnt;
    }
