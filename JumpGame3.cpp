/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array.
When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
Notice that you can not jump outside of the array at any time.

Example 1:
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation:
All possible ways to reach at index 3 with value 0 are:
index 5 -> index 4 -> index 1 -> index 3
index 5 -> index 6 -> index 4 -> index 1 -> index 3

Example 2:
Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true
Explanation:
One possible way to reach at index 3 with value 0 is:
index 0 -> index 4 -> index 1 -> index 3
*/


class Solution {
public:
    void helper(vector<int> &arr, int i, vector<bool> &v){
        int s=arr.size()-1;
        if(i>=0 and i<=s){
            v[i]=1;
            if(arr[i]==0)
                return;

            int k=i-arr[i];
            int h=i+arr[i];
            if(k>=0 and k<arr.size()){
                if(!v[k])
                    helper(arr,k,v);
            }
            if(h>=0 and h<arr.size()){
                if(!v[h])
                    helper(arr,h,v);
            }
        }
    return;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> v;
        for(auto i: arr)
            v.push_back(0);

        helper(arr,start,v);
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0 and v[i])
                return true;
        }
    return false;
    }
};
