/*
Given two numbers represented by two different arrays A and B. The task is to find the sum array. The sum array is an array representation of addition of two input arrays.

Example 1:
Input:
N = 3, M = 3
A[] = {5, 6, 3}
B[] = {8, 4, 2}
Output: 1 4 0 5
Explanation: As 563 + 842 = 1405.

Example 2:
Input:
N = 6, M = 4
A[] = {2, 2, 7, 5, 3, 3}
B[] = {4, 3, 3, 8}
Output: 2 3 1 8 7 1
Explanation: As 227533 + 4338 = 231871.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findSum() which takes the array(vector) of integers a and b as parameters and returns an array denoting the answer.

Expected Time Complexity: O(max(N, M))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ M ≤ 106
0 ≤ Ai, Bi ≤ 9
No leading zeroes in array A and B.
*/

/// For small Inputs only

	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    int num1=0, num2=0;
	    int n=a.size(), m=b.size();
	    for(int i=0;i<n;i++){
	        num1+=(a[i]*(pow(10,n-i-1)));
	    }
	    for(int i=0;i<m;i++){
	        num2+=(b[i]*(pow(10,m-i-1)));
	    }
	    int result=num1+num2;
	    vector<int> resultant;
	    while(result>0){
	        int temp=result%10;
	        resultant.push_back(temp);
	        result=result/10;
	    }
	   reverse(resultant.begin(),resultant.end());
	  return resultant;
	}


/// Generalized Solution

//User function template for C++
class Solution{
public:

	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    int n = a.size();
        int m = b.size();
        reverse(a.begin() , a.end());
        reverse(b.begin() , b.end());
        vector<int>sum;
        int carry = 0;
        int i = 0 , j = 0;
        while(i < n && j < m){
            int res = a[i] + b[j] + carry;
            int temp = res % 10;
            carry = res / 10;
            sum.push_back(temp);
            i++;
            j++;
        }
        while(i < n){
            int res = a[i] + carry;
            int temp = res % 10;
            carry = res / 10;
            sum.push_back(temp);
            i++;
        }
        while(j < m){
            int res = b[j] + carry;
            int temp = res % 10;
            carry = res / 10;
            sum.push_back(temp);
            j++;
        }
        if(carry > 0){
            sum.push_back(carry);
        }
        reverse(sum.begin() , sum.end());
        return sum;
    }
};
