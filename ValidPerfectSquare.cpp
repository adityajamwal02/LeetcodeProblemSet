/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Follow up: Do not use any built-in library function such as sqrt.

Example 1:
Input: num = 16
Output: true

Example 2:
Input: num = 14
Output: false
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left{1}, right{num}, middle{num/2};
        while(left<=right){
            float sqrt=(float)num/middle;
            if(sqrt==middle)
                return true;
            left = sqrt>middle ? middle+1 : left;
            right = sqrt<middle ? middle-1 : right;
            middle = left+(right-left)/2;
        }
    return 0;
    }
};
