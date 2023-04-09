/*
You are given 5 integers - N,A,B,C,D.
Let us say all the integers of length N, having only A or B in their decimal representation are good integers. Also, among all the good integers, all those integers whose sum of digits contains either C or D or both are best integers.
Find the number of best integers of length N. Since the number of best integers can be huge, print it modulo 109+7.


Example 1:

Input:
N = 2, A = 1, B = 2, C = 3, D = 5
Output:
2
Explanation:
The following are good integers:-
{ 12 , 22 , 11 , 21 }
And the following are best integers:-
{ 12, 21 } because sum of digits of 11,22
are 2 and 4, they are not equal to C or D.
Example 2:

Input:
N = 1, A = 1, B = 1, C = 2, D = 3
Output:
0
Explanation:
The following are good integers: - { 1 }
Since sum of digits is 1 which is not equal to
C or D, therefore, answer is 0.
Your Task:
The task is to complete the function solve() which takes five integers N,A,B,C and D as input parameters and returns the number of best integers modulo 109+7.

Expected Time Complexity: O(NlogN)
Expected Space Complexity: O(N)
*/

class Solution {
  public:
        int m= 1e9+7;

        void checkDigit(vector<int>&v,int sum){
            while(sum>0){
                int r= sum%10;
                v[r]=1;
                sum= sum/10;
            }
        }

        int binexp(int a,int b){
            int result=1;
            while(b>0){
                if(b&1)
                    result= (result* 1LL *a)%m;
                a= (a*1LL*a) %m;
                b= b>>1;
            }
            return result;
        }

        int bestNumbers(int N, int A, int B, int C, int D) {
            int total=0;
            vector<int>v(10,0);
            if(A==B){
                int sum= N*A;
                checkDigit(v,sum);
                if(v[C] or v[D]){
                    return 1;
                }
            }
            vector<int>dpfact(N+1,1);
            dpfact[0]=1;
            dpfact[1]=1;
            for(int i=2;i<=N;i++){
                dpfact[i]= (i* 1LL * dpfact[i-1])%m;
            }
            for(int i=0;i<=N;i++){
                int sum= i*A + (N-i)*B;
                v.clear();
                v.resize(10,0);
                checkDigit(v,sum);
                if(v[C] or v[D]){
                    int ans=0;
                    ans= dpfact[N];
                    int denom= (dpfact[i] * 1LL * dpfact[N-i]) % m;
                    ans= (ans*1LL*binexp(denom,m-2)) % m;
                    total= (total+ ans)%m;
                }
            }
        return total;
    }
};
