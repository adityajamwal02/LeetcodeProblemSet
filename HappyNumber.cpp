/*
Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:
Input: n = 2
Output: false
*/

/// 2 Pointer Approach (fast and slow)

class Solution {
public:
    int next(int n){
        int sum=0;
        while(n){
            int digits=n%10;
            n=n/10;
            sum+=digits*digits;

        }
        return sum;
    }

    bool isHappy(int n) {
        int slow=n;
        int fast=next(n);
        while(fast!=1 and slow!=fast){
            slow=next(slow);
            fast=next(next(fast));
        }
        return fast==1;
    }
};


/// Efficient Solution

class Solution {
public:
    int next(int n){
        int sum=0;
        while(n){
            int digits=n%10;
            n=n/10;
            sum+=digits*digits;

        }
        return sum;
    }

    bool isHappy(int n) {
        while(n!=1 and n!=4)
            n=next(n);

        return n==1;
    }
};
