/*
Given a number, reverse it and add it to itself unless it becomes a palindrome or number of iterations becomes more than 5.

Example 1:
Input: n = 23
Output: 55
Explanation: reverse(23) = 32,then 32+23
= 55 which is a palindrome.

Example 2:
Input: n = 30
Output: 33
Explanation: reverse(30) = 3,then 3+30
= 33 which is palindrome.

Your Task:
You dont need to read input or print anything. Complete the function isSumPalindrome() which takes n as input parameter and returns that palindrome number if it becomes a palindrome else returns -1.

Expected Time Complexity: O(n*k),where k<=5.
Expected Auxiliary Space: O(1)
*/


// User function Template for C++
class Solution {
  public:
    long long reverseNumber(long long n) {
        long long rev = 0;
        long long m = n;
        while(m>0) {
            int r = m%10;
            rev = (rev*10) + r;
            m = m/10;
        }
    return rev;
    }

    int isPalindrome(long long n) {
        long long rev = reverseNumber(n);
        return (n == rev) ? 1:0;
    }

    long long isSumPalindrome(long long n){
        if (isPalindrome(n)) {
            return n;
        }
        else {
            for (int i=0;i<5;i++) {
                long long m = reverseNumber(n);
                n = n + m;
                if (isPalindrome(n)) {
                    return n;
                }
            }
        }
        return -1;
    }

};
