/*
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in an ascending order, return compute the researcher's h-index.
According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.
If there are several possible values for h, the maximum one is taken as the h-index.
You must write an algorithm that runs in logarithmic time

Example 1:
Input: citations = [0,1,3,5,6]
Output: 3
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had received 0, 1, 3, 5, 6 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

Example 2:
Input: citations = [1,2,100]
Output: 2
*/

/// O(n) solution

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        for(int i=0;i<n;i++){
            if(citations[i]>=n-i){
                return n-i;
            }
        }
    return 0;
    }
};

/// O(logn) Solution

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int low=0, high=n-1, ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(citations[mid]>=n-mid){
                ans=n-mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    return ans;
    }
};
