/*
You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:
Input:
n=5
k=3
stalls = [1 2 4 8 9]
Output:
3
Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[2] and
the third cow can be placed at stalls[3].
The minimum distance between cows, in this case, is 3,
which also is the largest among all possible ways.

Example 2:
Input:
n=5
k=3
stalls = [10 1 2 7 5]
Output:
4
Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4,
which also is the largest among all possible ways.
Your Task:
Complete the function int solve(), which takes integer n, k, and a vector stalls with n integers as input and returns the largest possible minimum distance between cows.

Expected Time Complexity: O(n*log(10^9)).
Expected Auxiliary Space: O(1).
*/

class Solution {
public:
    bool isValid(int n, int k, vector<int> &stalls, int mid){
        int cow=1, curr=stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i]-curr>=mid){
                cow++;
                curr=stalls[i];
            }
            if(cow==k) return true;
        }
    return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int left=1, right=stalls[n-1]-stalls[0];
        int res=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(n,k,stalls,mid)){
                res=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
    return res;
    }
};
