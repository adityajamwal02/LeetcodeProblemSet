/*
Given two arrays a[] and b[] of same size.Your task is to find minimum sum of two elements such that they belong to different arrays and are not at same index in their arrays.

Example 1:
Input :
a[] = {5, 4, 13, 2, 1}
b[] = {2, 3, 4, 6, 5}
Output :
3
Explanation :
We take 1 from a[] and 2 from b[]
Sum is 1 + 2 = 3.

Example 2:
Input :
a[] = {5, 4, 13, 1}
b[] = {3, 2, 6, 1}
Output :
3
Explanation :
We take 1 from a[] and 2 from b[].
Note that we can't take 1 from b[]
as the elements can not be at same
index.

Your Task:
You don't need to read input or print anything. Your task is to complete the function minSum() which takes the array A[], B[] and its size N as inputs and returns the minimum sum.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

//User function Template for C++

class Solution{
    public:
    int minSum(int arr1[], int arr2[], int n)
    {
        if(n==1) return 0;
        int min1=INT_MAX;
        int min2=INT_MAX;
        int index1=-1, index2=-1;
        for(int i=0;i<n;i++){
            if(arr1[i]<=min1){
                min2=min1;
                index2=index1;
                min1=arr1[i];
                index1=i;
            }else if(arr1[i]<min2 and min1!=min2){
                min2=arr1[i];
                index2=i;
            }
        }

        int min3=INT_MAX;
        int min4=INT_MAX;
        int index3=-1, index4=-1;
        for(int i=0;i<n;i++){
            if(arr2[i]<=min3){
                min4=min3;
                index4=index3;
                min3=arr2[i];
                index3=i;
            }else if(arr2[i]<min4 and min3!=min4){
                min4=arr2[i];
                index4=i;
            }
        }
        if(index1!=index3){
            return min1+min3;
        }else{
            return min(min1+min4, min2+min3);
        }

    }
};
