/*
Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Example 1:

Input:
n = 1
Output: 5
Explanation : 5! = 120 which has at
least 1 trailing 0.
Example 2:

Input:
n = 6
Output: 25
Explanation : 25! has at least
6 trailing 0.

User Task:
Complete the function findNum() which takes an integer N as input parameters, and returns the answer.

Expected Time Complexity: O(log2 N * log5 N).
Expected Auxiliary Space: O(1).
*/


class Solution
{
    public:
        int solve(int mid){
            int res=0;
            while(mid){
                res+=mid/5;
                mid=mid/5;
            }
        return res;
        }

        int findNum(int n)
        {
            int start=1, end=n*5;
            int ans;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(solve(mid)>=n){
                    end=mid-1;
                    ans=mid;
                }else{
                    start=mid+1;
                }
            }
        return ans;
        }
};
