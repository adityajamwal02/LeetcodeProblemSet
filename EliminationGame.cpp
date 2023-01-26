/*
You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:
Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
Given the integer n, return the last number that remains in arr.

Example 1:
Input: n = 9
Output: 6
Explanation:
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
arr = [2, 4, 6, 8]
arr = [2, 6]
arr = [6]

Example 2:
Input: n = 1
Output: 1

*/

/// Pattern (Math)

class Solution {
public:
    int lastRemaining(int n) {
        if(n==1) return 1;
    return 2*(1+n/2 - lastRemaining(n/2));
    }
};


/// Two Pointers

class Solution {
public:
    bool changeBothPtr(int& left, int& right, int& step) {
        return !((right - left) % step);
    }

    int lastRemaining(int n) {
        int left = 1, right = n, step = 2, pos = 0;

        while (left < right) {
            if (changeBothPtr(left, right, step)) {
                left+= (step / 2);
                right-= (step / 2);
            }
            else {
                if (pos) right-= (step / 2);
                else left+= (step / 2);
            }
            pos = 1 - pos;
            step*= 2;
        }
        return left;
    }
};


/// Intuition

int lastRemaining(int n) {
        int start=1,diff=1,no=n;
        bool left2right=true;
        while(no>1){
            if(left2right||no%2==1)
                start+=diff;
            diff*=2;
            no/=2;
            left2right=!left2right;
        }
        return start;
    }
