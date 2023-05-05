/*
Given an integer, check whether it is a palindrome or not.

Example 1:

Input: n = 555
Output: Yes

Example 2:

Input: n = 123
Output: No


Your Task:
You don't need to read or print anything. Your task is to complete the function is_palindrome() which takes the number as input parameter and returns "Yes" if it is palindrome otherwise returns "No"(Without quotes).


Expected Time Complexity: O(x)
Expected Space Complexity: O(x) where x is number of digits in n.


Constraints:
1 <= n <= 1000
*/

//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    string temp=to_string(n);
		    string temp2=temp;
		    reverse(temp2.begin(),temp2.end());
    		if(temp==temp2){
    		    return "Yes";
    		}
    	return "No";
		}
};

