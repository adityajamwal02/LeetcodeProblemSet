/*
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.
For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

Example 1:
Input: columnTitle = "A"
Output: 1

Example 2:
Input: columnTitle = "AB"
Output: 28

Example 3:
Input: columnTitle = "ZY"
Output: 701
*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.size();
        int ans=0;
        for(int i=0;i<n;i++){
            char ch=columnTitle[i];
            int digit=ch-'A'+1;
            ans=(ans*26 + digit);
        }
    return ans;
    }
};
