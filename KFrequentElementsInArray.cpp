/*
Given a non-empty array of integers, find the top k elements which have the highest frequency in the array. If two numbers have the same frequency then the larger number should be given preference.

Note: Print the elements according to the frequency count (from highest to lowest) and if the frequency is equal then larger number will be given preference.

Example 1:

Input:
N = 6
nums = {1,1,1,2,2,3}
k = 2
Output: {1, 2}
Example 2:

Input:
N = 8
nums = {1,1,2,2,3,3,3,4}
k = 2
Output: {3, 2}
Explanation: Elements 1 and 2 have the
same frequency ie. 2. Therefore, in this
case, the answer includes the element 2
as 2 > 1.
*/

#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
     unordered_map<int, int> mp;
        vector<int> result;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        sort(result.begin(), result.end());
    return result;
}
