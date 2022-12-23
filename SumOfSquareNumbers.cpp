/*
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: c = 3
Output: false
*/


/// Better Brute Force

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long i=0;i*i<=c;i++){
            double j=sqrt(c- i*i);
            if(j==(int)j)
                return true;
         }
    return false;
    }
};


/// Binary Search

class Solution {
public:
    bool binarySearch(long start, long end, int n){
        if(start>end)
            return false;
        long mid=start+(end-start)/2;
        if(mid*mid==n)
            return true;
        if(mid*mid>n)
            return binarySearch(start,mid-1,n);
    return binarySearch(mid+1,end,n);
    }
    bool judgeSquareSum(int c) {
        for(long i=0;i*i<=c;i++){
            int j=c-(int)(i*i);
            if(binarySearch(0,j,j))
                return true;
         }
    return false;
    }
};
