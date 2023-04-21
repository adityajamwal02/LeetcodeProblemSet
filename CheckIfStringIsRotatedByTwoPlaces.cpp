/*
Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating another string 'a' by exactly 2 places.

Example 1:

Input:
a = amazon
b = azonam
Output: 1
Explanation: amazon can be rotated anti
clockwise by two places, which will make
it as azonam.
Example 2:

Input:
a = geeksforgeeks
b = geeksgeeksfor
Output: 0
Explanation: If we rotate geeksforgeeks by
two place in any direction , we won't get
geeksgeeksfor.
Your Task:
The task is to complete the function isRotated() which takes two strings as input parameters and checks if given strings can be formed by rotations. The function returns true if string 1 can be obtained by rotating string 2 by two places, else it returns false.

Expected Time Complexity: O(N).
Expected Auxilary Complexity: O(N).
Challenge: Try doing it in O(1) space complexity.
*/

class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int n=str1.size();
        if(n!=str2.size()) return false;
        if(n<=2) return (str1==str2);
        string clockwise=str1.substr(2)+str1.substr(0,2);
        string anticlock=str1.substr(n-2)+str1.substr(0,n-2);
    return (str2==clockwise or str2==anticlock);
    }

};

/// O(1) Space

bool isRotated(string str1, string str2){
    int n = str1.length();
    if (n != str2.length())
        return false;
    if (n <= 2)
        return (str1 == str2);
    for (int i = 0; i < n; i++) {
        if (str1[(i+2)%n] != str2[i])
            break;
        if (i == n-1)
            return true;
    }
    for (int i = 0; i < n; i++) {
        if (str1[(n+i-2)%n] != str2[i])
            break;
        if (i == n-1)
            return true;
    }
    return false;
}

