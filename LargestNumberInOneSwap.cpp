/*
Given a non-negative number N in the form of a string.Find the largest number that can be formed by swapping two characters at most once.

Example 1:
Input:
N=768
Output:
867
Explanation:
Swapping the 1st and 3rd
characters(7 and 8 respectively),
gives the largest possible number.

Example 2:
Input:
N=333
Output:
333
Explanation:
Performing any swaps gives the
same result i.e 333.

Your Task:
You don't need to read input or print anything. Your task is to complete the function LargestSwap() which takes the string N as input parameter and returns the maximum possible string possible with at most one swap.
Expected Time Complexity:O(|N|)
Expected Auxillary Space:O(1)
*/

// User functiom template for C++

class Solution {
  public:
    string LargestSwap(string S) {
        int n=S.size();
        for(int i=0;i<n;i++){
            char ch=S[i];
            int max_index=i;
            for(int j=i+1;j<n;j++){
                if(S[j]>=ch){
                    ch=S[j];
                    max_index=j;
                }
            }
            if(ch>S[i]){
                swap(S[i], S[max_index]);
                break;
            }
        }
    return S;
    }
};
