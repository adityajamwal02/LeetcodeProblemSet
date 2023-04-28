/*
Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.

Example 1:
Input:
N = 5
arr[] = {4,1,3,9,7}
Output:
1 3 4 7 9
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.

Example 2:
Input:
N = 10
arr[] = {10,9,8,7,6,5,4,3,2,1}
Output:
1 2 3 4 5 6 7 8 9 10
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1, 2,3,4,5,6,7,8,9,10.

Your Task :
You don't have to read input or print anything. Your task is to complete the functions heapify(), buildheap() and heapSort() where heapSort() and buildheap() takes the array and it's size as input and heapify() takes the array, it's size and an index i as input. Complete and use these functions to sort the array using heap sort algorithm.
Note: You don't have to return the sorted list. You need to sort the array "arr" in place.

Expected Time Complexity: O(N * Log(N)).
Expected Auxiliary Space: O(1).
*/


class Solution
{
    public:

    void heapify(int arr[], int n, int i)
    {
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n and arr[left]>arr[largest]){
            largest=left;
        }
        if(right<n and arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }

    void buildHeap(int arr[], int n)
    {
    }


    void heapSort(int arr[], int n)
    {
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }

        for(int i=n-1;i>0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
};


/// Another Solution

/// Building heap using n/2-1 to >=0



class Solution
{
    public:

    void heapify(int arr[], int n, int i)
    {
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n and arr[left]>arr[largest]){
            largest=left;
        }
        if(right<n and arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }

    void buildHeap(int arr[], int n)
    {
         for(int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }

    }

    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);

        for(int i=n-1;i>0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
};
