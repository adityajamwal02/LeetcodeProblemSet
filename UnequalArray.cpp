/*
You are given two arrays A and B each of length N. You can perform the following operation on array A zero or more times.

Select any two indices i and j, 1 <= i , j <= N and i != j
Set A[i] = A[i] + 2 and A[j] = A[j]-2
Find the minimum number of operations required to make A and B equal.

Note :

Two arrays are said to be equal if the frequency of each element is equal in both of them.
Arrays may contain duplicate elements.
Example 1:

Input:
N = 3
A[] = {2, 5, 6}
B[] = {1, 2, 10}
Output: 2
Explanation:
Select i = 3, j = 2, A[3] = 6 + 2 = 8 and A[2] = 5 - 2 = 3
Select i = 3, j = 2, A[3] = 10 - 2 = 8 and A[2] = 3 - 2 = 1
Now A = {2, 1, 10} and B = {1, 2, 10}
Example 2:

Input:
N = 2
A[] = {3, 3}
B[] = {9, 8}
Output: -1
Explanation:
It can be shown that A cannot be made equal to B.
Your Task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes the 2 arrays A[], B[] and their size N as input parameters and returns the minimum number of moves to make A and B equal if possible else return -1.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)
*/


class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        long long result=0;
        int x=0, y=0, s1=0, s2=0;
        for(int i : A){
            if(i%2) x++; s1+=i;
        }
        for(int i : B){
            if(i%2) y++; s2+=i;
        }
        if(s1!=s2 or x!=y) return -1;
        vector<int> a,b,c,d;
        for(int i=0;i<N;i++){
            if(A[i]%2){
                a.push_back(A[i]);
            }else{
                b.push_back(A[i]);
            }
            if(B[i]%2){
                c.push_back(B[i]);
            }else{
                d.push_back(B[i]);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
        for(int i=0;i<a.size();i++){
            result+=(abs(c[i]-a[i]));
        }
        for(int i=0;i<b.size();i++){
            result+=(abs(d[i]-b[i]));
        }
    return result/4;
    }
};
