/*
Given a sorted array arr[] of size N. Find the element that appears only once in the array. All other elements appear exactly twice.

Example 1:

Input:
N = 11
arr[] = {1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65}
Output: 4
Explanation: 4 is the only element that
appears exactly once.


Your Task:
You don't need to read input or print anything. Complete the function findOnce() which takes sorted array and its size as its input parameter and returns the element that appears only once.


Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)


*/

class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto it : mp){
            if(it.second==1){
                return it.first;
            }
        }
    return -1;
    }
};
