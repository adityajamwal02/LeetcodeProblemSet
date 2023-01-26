/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
Example 1:
Input: n = 13
Output: 6

Example 2:
Input: n = 0
Output: 0
*/


class Solution {
public:
    int countDigitOne(int n) {
        int ones=0;
        for(int i=1;i<=n;i*=10){
            int a=n/i, b=n%i;
            ones+= (a+8)/10 * i + (a%10==1) * (b+1);
        }
    return ones;
    }
};

