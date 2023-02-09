/*
You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.



Example 1:

Input: start = "_L__R__R_", target = "L______RR"
Output: true
Explanation: We can obtain the string target from start by doing the following moves:
- Move the first piece one step to the left, start becomes equal to "L___R__R_".
- Move the last piece one step to the right, start becomes equal to "L___R___R".
- Move the second piece three steps to the right, start becomes equal to "L______RR".
Since it is possible to get the string target from start, we return true.

Example 2:
Input: start = "R_L_", target = "__LR"
Output: false
Explanation: The 'R' piece in the string start can move one step to the right to obtain "_RL_".
After that, no pieces can move anymore, so it is impossible to obtain the string target from start.
Example 3:

Input: start = "_R", target = "R_"
Output: false
Explanation: The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.
*/

/// !st Solution

class Solution {
public:
    bool canChange(string start, string target) {
        int i=0, j=0, n=start.size();
        int startcountLeft=0, targetcountLeft=0, startcountRight=0, targetcountRight=0;
        for(int i=0;i<n;i++){
            if(start[i]=='R') startcountRight++;
            else if(start[i]=='L') startcountLeft++;

            if(target[i]=='L') targetcountLeft++;
            else if(target[i]=='R') targetcountRight++;

        }
        if((startcountLeft!=targetcountLeft or startcountRight!=targetcountRight)){
            return false;
        }
        while(i<n and j<n){
            while(i<n and start[i++]=='_');
            while(j<n and target[j++]=='_');
            i--;
            j--;
            if(start[i]!=target[j]) return false;
            if(start[i]=='L'){
                if(i<j) return false;
            }
            if(start[i]=='R'){
                if(i>j) return false;
            }
            i++;
            j++;
        }
    return true;
    }
};


/// 2nd solution

bool canChange(string s, string t) {
    int i = 0, j = 0, n = s.size();
    for (; i < n || j < n; ++i, ++j) {
        while (i < n && s[i] == '_')
            ++i;
        while (j < n && t[j] == '_')
            ++j;
        if (i == n || j == n || s[i] != t[j] || (s[i] == 'L' && i < j) || (s[i] == 'R' && i > j))
            break;
    }
    return i == n && j == n;
}
