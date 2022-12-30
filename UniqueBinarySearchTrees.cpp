/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
Example 1:
Input: n = 3
Output: 5
Example 2:
Input: n = 1
Output: 1
*/


/// Tabulation

class Solution {
public:
    int numTrees(int n) {
       long long ans=1;
       for(int i=1;i<n;i++){
           ans*=(n+1+i);
           ans/=i;
       }
       ans=ans/n;
    return ans;
    }
};
