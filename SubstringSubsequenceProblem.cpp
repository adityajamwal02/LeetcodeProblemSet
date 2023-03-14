/*
Find the longest subsequence X of a string A which is a substring Y of a string B.
Note: All letters of the Strings are Uppercased.

Example 1:
Input:
A = "ABCD" , B = "BACDBDCD"
Output:
3
Explanation:
The answer would be 3 as because "ACD"
is the longest subsequence of A which
is also a substring of B.

Example 2:
Input:
A = "A" , B = "A"
Output:
1
Explanation:
The answer would be 1 as because "A"
is the longest subsequence of A which
is also a substring of B.

Your Task:
You don't need to read input or print anything. Your task is to complete the function getLongestSubsequence() which takes Strings A  and B as input and returns the answer.

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(|S|2)
*/


class Solution {
  public:
    int getLongestSubsequence(string A, string B) {
        int n = A.size();
        int m = B.size();
        int result=0;
        for(int i=0;i<m;i++){
            int k = i;
            int count=0;
            for(int j=0;j<n;j++){
                if(k<m and B[k]==A[j]){
                    k++;
                    count++;
                }
            }
        result=max(result,count);
        }
    return result;
    }
};
