/*
Given is a range of integers [a , b]  . You have to find the sum of all the numbers in the range  [a , b] that are prime as well as palindrome.

Example 1:
Input:
a = 1, b = 10
Output:
17
Explanation:
prime numbers between 1 and 10 are 2, 3,
5, and 7. All of these are Palindromes.
So, sum = 17.

Example 2:
Input:
a = 11, b = 13
Output:
11
Explanation:
prime numbers between 11 and 13 are 11
and 13. Omly 11 is Palindrome among these.
So, sum = 11.

Your Task:
You don't need to read input or print anything. Your task is to complete the function getPPS() which takes 2 Integers a and b as input and returns an integer as the answer.

Expected Time Complexity: O(loglog(B))
Expected Auxiliary Space: O(B)
*/


//User function Template for C++

class Solution {
  public:
    bool isPrime(int num){
        if(num==1) return false;
        int i;
        for(i=2;i<=sqrt(num);i++){
            if(num%i==0) break;
        }
    return (i>sqrt(num)) ? true : false;
    }

    bool isPalindrome(int num){
        string temp=to_string(num);
        string revTemp=temp;
        reverse(revTemp.begin(), revTemp.end());

    return (revTemp==temp);
    }

    long long getPPS(int a, int b) {
        long long result=0;
        for(int i=a;i<=b;i++){
            if(isPrime(i) and isPalindrome(i)){
                result+=i;
            }
        }
    return result;
    }
};
