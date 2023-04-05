/*
You are given an array arr[ ] of size N consisting of only positive integers. Your task is to find the count of special numbers in the array. A number is said to be a special number if it is divisible by at least 1 other element of the array.

Example 1:

Input:
N = 3
arr[] = {2, 3, 6}
Output:
1
Explanation:
The number 6 is the only special number in the
array as it is divisible by the array elements 2
and 3. Hence, the answer is 1 in this case.
Example 2:

Input:
N = 4
arr[] = {5, 5, 5, 5}
Output:
4
Explanation:
All the array elements are special. Hence,
the answer is 4 in this case.
Your Task:
You don't need to read input or print anything. Complete the function countSpecialNumbers() which takes the integer N and the array arr[ ] as the input parameters, and returns the count of special numbers in the array.


Expected Time Complexity: O(N*root(M)) where M = max(arr[i])
Expected Auxiliary Space: O(N)


*/


// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        int result=0;
        for(int i=0;i<N;i++){
            mp[arr[i]]++;
        }
        for(auto it : mp){
            if(it.second>1){
                result+=it.second;
            }else{
                for(int j=0;j<N;j++){
                    if(arr[j]>=it.first) continue;
                    else{
                        if(it.first%arr[j]==0){
                            result++;
                            break;
                        }
                    }
                }
            }
        }
    return result;
    }
};
