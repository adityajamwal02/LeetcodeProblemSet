/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
You must solve the problem without using any built-in library for handling large integers (such as BigInteger).
You must also not convert the inputs to integers directly.

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"
*/

class Solution {
public:
    string addStrings(string a, string b) {
    int i=a.length()-1;
    int j=b.length()-1;
    int sum=0,ten=0;
    string ans;
    while(i>=0&&j>=0)
    {
        sum=int(a[i]-'0')+int(b[j]-'0')+ten;
        ans.push_back(char(sum%10+48));
        ten=sum/10;
        i--;j--;

    }
    if(i>=0)
    {
        while(i>=0)
     {
        sum=int(a[i]-'0')+ten;
        ans.push_back(char(sum%10+48));
        ten=sum/10;
        i--;

     }

    }
    if(j>=0)
    {
        while(j>=0)
       {
        sum=int(b[j]-'0')+ten;
        ans.push_back(char(sum%10+48));
        ten=sum/10;
        j--;

     }

    }
    if(sum>9)
    {
        ans.push_back(char(sum/10+48));
    }

      reverse(ans.begin(), ans.end());
      return ans;
    }
};
