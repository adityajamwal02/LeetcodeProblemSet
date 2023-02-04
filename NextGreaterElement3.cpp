/*
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n.
If no such positive integer exists, return -1.
Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

Example 1:
Input: n = 12
Output: 21

Example 2:
Input: n = 21
Output: -1
*/

class Solution {
public:
    bool nextPermutation(string &num){
        int n=num.size();
        int i=n-1;
        while(i>0 and num[i-1]>=num[i]) i--;
        if(i==0) return false;
        int j=n-1;
        while(j>0 and num[j]<=num[i-1]) j--;
        swap(num[i-1],num[j]);
        reverse(num.begin()+i,num.end());
    return true;
    }
    int nextGreaterElement(int n) {
        string str=to_string(n);
        bool result=nextPermutation(str);
        if(!result)
            return -1;
    return stoll(str)>INT_MAX ? -1 : stoi(str);
    }
};
