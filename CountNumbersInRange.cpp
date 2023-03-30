/*
Given two positive integers L and R, return count of numbers having exactly 3 divisors from L to R inclusive.

Example 1:
Input:
L = 1, R = 10
Output:
2
Explanation:
4 and 9 are two numbers between 1 and 10
and have exactly 3 divisors.

Example 2:
Input:
L = 2, R = 5
Output:
1
Explanation:
4 is the only number between 2 and 5
and have exactly 3 divisors.
*/



class Solution {
  public:
    bool isPrime(int n){
        if(n<2) return false;
        if(n==2 or n==3) return true;
        if(n%2==0 or n%3==0) return false;
        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 or n%(i+2)==0){
                return false;
            }
        }
    return true;
    }
    int count3DivNums(long long L, long long R) {
        int counter=0;
        for(int i=1;i*i<=R;i++){
            int a=i*i;
            if(isPrime(i) and (L<=a and a<=R)){
                counter++;
            }
        }
    return counter;
    }
};
