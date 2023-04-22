/*
Given an integer N, find its factorial. return a list of integers denoting the digits that make up the factorial of N.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Your Task:
You don't need to read input or print anything. Complete the function factorial() that takes integer N as input parameter and returns a list of integers denoting the digits that make up the factorial of N.


Expected Time Complexity : O(N2)
Expected Auxilliary Space : O(1)
*/

//User function template for C++

class Solution {
public:


    vector<int> factorial(int N){
        vector<int> result;
        result.push_back(1);
        for(int i=2;i<=N;i++){
            int carry=0;
            for(int j=result.size()-1;j>=0;j--){
                int val=(i*result[j]+carry);
                result[j]=val%10;
                carry=val/10;
            }
            while(carry>0){
                result.insert(result.begin(),carry%10);
                carry/=10;
            }
        }
    return result;
    }
};
