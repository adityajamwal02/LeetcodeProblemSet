/*
Given a string str, find the minimum characters to be added at front of the string to make it a palindrome.

Example 1:
Input:
str = ABCD
Output: 3
Explanation: The resultant string
after adding 3 characters is DCBABCD.
The minimum possible answer is 3.

Example 2:
Input:
str = ABA
Output: 0
Explanation: The given string
is already a palindrome.

Your Task:
You don't need to read input or print anything. Your task is to complete the function addMinChar() which takes the string str as input parameters and returns the minimum number of characters to be added to make it a palindrome.

Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)
*/

//User function Template for C++

class Solution{
public:
    bool isPalindrome(string str){
        string temp=str;
        reverse(temp.begin(),temp.end());
    return (temp==str);
    }
    int addMinChar(string str){
        if(isPalindrome(str)) return 0;
        int n=str.size();
        int i=0, j=n-1;
        while(i<j){
            if(str[i]==str[j]){
                int x=i;
                int y=j;
                while(x<y and str[x]==str[y]){
                    x++;
                    y--;
                }
                if(x>=y){
                    i=x;
                    j=y;
                }else{
                    j--;
                }
            }else{
                j--;
            }
        }
        int x = n-1-j;
        int y = i;
    return x-y;
    }
};
