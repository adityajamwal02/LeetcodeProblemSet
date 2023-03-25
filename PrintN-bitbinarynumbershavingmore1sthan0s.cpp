/*
Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

Example 1:
Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than
or equal 1's than 0's

Example 2:
Input:  N = 3
Output: 111 110 101
Explanation: 111, 110 and 101 have more
than or equal 1's than 0's
User Task:
Your task is to complete the function NBitBinary() which takes a single number as input and returns the list of strings in decreasing order. You need not take any input or print anything.
*/

/// Recursion

//User function template for C++
class Solution{
public:
    void solve(int zero, int one, int n, string output, vector<string> &result){
        if(n==0){
            result.push_back(output);
            return;
        }
        solve(zero, one+1, n-1, output+'1', result);
        if(one>zero){
            solve(zero+1, one, n-1, output+'0', result);
        }
    return;
    }
	vector<string> NBitBinary(int N)
	{
	    vector<string> result;
	    string output="";
	    solve(0, 0, N, output, result);
	return result;
	}
};
