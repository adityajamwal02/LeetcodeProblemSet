/*
Given two arrays X and Y of positive integers, find the number of pairs such that xy > yx (raised to power of) where x is an element from X and y is an element from Y.

Example 1:

Input:
M = 3, X[] = [2 1 6]
N = 2, Y[] = [1 5]
Output: 3
Explanation:
The pairs which follow xy > yx are
as such: 21 > 12,  25 > 52 and 61 > 16 .
Example 2:

Input:
M = 4, X[] = [2 3 4 5]
N = 3, Y[] = [1 2 3]
Output: 5
Explanation:
The pairs for the given input are
21 > 12 , 31 > 13 , 32 > 23 , 41 > 14 ,
51 > 15 .

Your Task:
This is a function problem. You only need to complete the function countPairs() that takes X, Y, M, N as parameters and returns the total number of pairs.

Expected Time Complexity: O((N + M)log(N)).
Expected Auxiliary Space: O(1).
*/

/// Brute Force

long long countPairs(int X[], int Y[], int M, int N)
    {
       long long counter=0;
       for(int i=0;i<M;i++){
           for(int j=0;j<N;j++){
               if(pow(X[i],Y[j])>pow(Y[j],X[i])){
                   counter++;
               }
           }
       }
       return counter;
    }
};


/// Optimized



class Solution{
    public:

    // X[], Y[]: input array
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.

    int getIndex(int arr[], int n, int c){
        int low=0, high=n-1, ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>c){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    return ans;
    }

    long long countPairs(int X[], int Y[], int M, int N)
    {
        long long zero=0, one=0, two=0, three=0, four=0;
        long long ans=0;
        sort(Y,Y+N);
        for(int i=0;i<N;i++){
            if(Y[i]==0) zero++;
            else if(Y[i]==1) one++;
            else if(Y[i]==2) two++;
            else if(Y[i]==3) three++;
            else if(Y[i]==4) four++;
        }
        for(int i=0;i<M;i++){
            if(X[i]==0) continue;
            else if(X[i]==1){
                ans+=zero;
            }else if(X[i]==2){
                int index=getIndex(Y,N,2);
                if(index!=-1){
                    ans+=(N-index);
                }
                ans-=three;
                ans-=four;
                ans+=one+zero;
            }else if(X[i]==3){
              int index=getIndex(Y,N,3);
              if(index!=-1){
                  ans+=N-index;
                }
              ans+=two;
              ans+=one+zero;
            }else{
              int index=getIndex(Y,N,X[i]);
              if(index!=-1){
                  ans+=N-index;
            }
            ans+=one+zero;
        }
    }
    return ans;
   }
};

