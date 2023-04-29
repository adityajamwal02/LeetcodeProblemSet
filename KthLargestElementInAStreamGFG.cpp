/*
Given an input stream arr[] of n integers. Find the Kth largest element for each element in the stream and if the Kth element doesn't exist, return -1.

Example 1:

Input:
k = 4, n = 6
arr[] = {1, 2, 3, 4, 5, 6}
Output:
-1 -1 -1 1 2 3
Explanation:
k = 4
For 1, the 4th largest element doesn't
exist so we print -1.
For 2, the 4th largest element doesn't
exist so we print -1.
For 3, the 4th largest element doesn't
exist so we print -1.
For 4, the 4th largest element is 1.
For 5, the 4th largest element is 2.
for 6, the 4th largest element is 3.
Example 2:

Input:
k = 1, n = 2
arr[] = {3, 4}
Output:
3 4
Explanation:
For the 1st and 2nd element the 1st largest
element is itself.


Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes 2 Integers k, and n and also an array arr[] of size n as input and returns the kth largest element in the stream.



Expected Time Complexity: O(nlogk)
Expected Auxiliary Space: O(n)
*/


class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> result(n,0);
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
            result[i]=-1;
        }
        result[k-1]=pq.top();
        for(int i=k;i<n;i++){
            if(pq.top()<arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
            result[i]=pq.top();
        }
    return result;
    }
};

/// Easy Code

class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {

        // code here

        vector<int>v;

        priority_queue<int,vector<int>,greater<int>>pq;

        int i;

        for(i=0;i<n;i++)

        {

            pq.push(arr[i]);

            if(pq.size()<k)

            v.push_back(-1);

            if (pq.size() > k)

            {

               pq.pop();

            }

            if(pq.size() == k)

            {

              v.push_back(pq.top());

            }

        }

        return v;

    }
};
