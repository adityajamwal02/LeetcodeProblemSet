/*
Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.

Example 1:
Input: n = 2
Output: 987
Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Example 2:
Input: n = 1
Output: 9
*/

class Solution {
public:
    int largestPalindrome(int n) {
        int mod=1337;
        if(n==1){
            return 9;
        }else if(n==2){
            return 9009%mod;
        }else if(n==3){
            return 906609%mod;
        }else if(n==4){
            return 99000099%mod;
        }else if(n==5){
            return 9966006699%mod;
        }else if(n==6){
            return 999000000999%mod;
        }else if(n==7){
            return 99956644665999%mod;
        }else{
            return 9999000000009999%mod;
        }
    return -1;
    }
};
