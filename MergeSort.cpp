/*
Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.

Example 1:
Input:
N = 5
arr[] = {4 1 3 9 7}
Output:
1 3 4 7 9

Example 2:
Input:
N = 10
arr[] = {10 9 8 7 6 5 4 3 2 1}
Output:
1 2 3 4 5 6 7 8 9 10

Your Task:
You don't need to take the input or print anything. Your task is to complete the function merge() which takes arr[], l, m, r as its input parameters and modifies arr[] in-place such that it is sorted from position l to position r, and function mergeSort() which uses merge() to sort the array in ascending order using merge sort algorithm.

Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)
*/



class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int leftSize=m-l+1;
        int rightSize=r-m;
        vector<int> left(leftSize), right(rightSize);
        for(int i=0;i<leftSize;i++){
            left[i]=arr[l+i];
        }
        for(int j=0;j<rightSize;j++){
            right[j]=arr[m+1+j];
        }
        auto index_first=0, index_second=0, index_merged=l;
        while(index_first<leftSize and index_second<rightSize){
            if(left[index_first]<=right[index_second]){
                arr[index_merged]=left[index_first];
                index_first++;
            }else{
                arr[index_merged]=right[index_second];
                index_second++;
            }
            index_merged++;
        }
         while(index_first<leftSize){
            arr[index_merged]=left[index_first];
            index_first++;
            index_merged++;
         }
         while(index_second<rightSize){
            arr[index_merged]=right[index_second];
            index_second++;
            index_merged++;
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return;
        auto m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
};
