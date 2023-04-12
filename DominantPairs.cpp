/*
You are given an array of integers of size n where n being even.. You have to calculate the number of dominate pairs (i,j) . Where a pair is called dominant if ( 0<=i<n/2, n/2<=j<n, arr[i]>=5*arr[j] ) these relation are fulfilled.  For example  in arr=[10,3,3,1] index i=0, j=3 form a dominating pair
Note : 0 based indexing is used  and n is even

Example 1:
Input:
n=4
arr={10,2,2,1}
Output:
2
Explanation:
As we can see index i=0 and j=2 where
arr[0]>=5*arr[2] (10>=5*2)is fulfilled so
this forms a dominant pair and in same
manner index i=0 and j=3 forms dominant
pair.So total 2 dominant pairs.

Example 2:
Input:
n=6
arr={10,8,2,1,1,2}
Output:
5
Explanation:
As we can see index i=0 and j=3 where
arr[0]>=5*arr[3] (10>=5*1) is fulfilled so
this forms a dominant pair and in same
manner (0,4),(0,5),(1,3),(1,4) also form
dominant pair.So total 5 dominant pairs.
Your Task:
You don't need to read input or print anything. Your task is to complete the function dominantPairs() which takes an integer n and an array of integers arr respectively and returns the count of dominate pairs.

Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(1)
*/


//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        int counter=0;
        int mid=n/2;
        sort(arr.begin(),arr.begin()+mid);
        sort(arr.begin()+mid,arr.end());
        int left=n/2-1, right=n-1;
        while(left>=0 and right>=n/2){
            if(arr[left]>=5*arr[right]){
                counter+=(right-n/2+1);
                left--;
            }else{
                right--;
            }
        }
    return counter;
    }
};

