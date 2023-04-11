/*
Given the maximum occurrences of a, b, and c in a string. Your task is to make the largest length string containing only a, b, and c such that no three consecutive characters are the same. Return the longest possible string length.

Example 1:
Input:
a = 3, b = 3, c = 3
Output:
9
Explanation:
No three consecutive character of
the string "abcabcabc" is same.

Example 2:
Input:
a = 11, b = 2, c = 2
Output:
-1
Explanation:
If we build a string of these character's,
the string will be"aabaacaabaacaaa", here
we can see that there will be three consecutive a. So
there is no solution exist.
Your Task:
You don't need to read input or print anything. Your task is to complete the function solve( ) which takes integers a, b, and c as input parameters and returns the longest possible string length. If there is no possible answer return -1.

Expected Time Complexity: O(a+b+c)
Expected Auxiliary Space: O(1)
*/

// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        if(a>2*(b+c+1) or b>2*(a+c+1) or c>2*(a+b+1)) return -1;
    return (a+b+c);
    }
};
