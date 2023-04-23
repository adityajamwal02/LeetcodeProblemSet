/*
You are given an array target that consists of distinct integers and another integer array arr that can have duplicates.

In one operation, you can insert any integer at any position in arr. For example, if arr = [1,4,1,2], you can add 3 in the middle and make it [1,4,3,1,2]. Note that you can insert the integer at the very beginning or end of the array.

Return the minimum number of operations needed to make target a subsequence of arr.

A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.



Example 1:

Input: target = [5,1,3], arr = [9,4,2,3,4]
Output: 2
Explanation: You can add 5 and 1 in such a way that makes arr = [5,9,4,1,2,3,4], then target will be a subsequence of arr.
Example 2:

Input: target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
Output: 3

*/



/// LCS Tabulation

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n=arr.size();
        int m=target.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i-1]==target[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return m-dp[n][m];
    }
};

/// Efficient LCS --> LIS (using maps)


class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        int m=arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[target[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            if(mp.find(arr[i])!=mp.end()){
                int index=mp[arr[i]];
                auto x=lower_bound(ans.begin(), ans.end(),index);
                if(x!=ans.end()){
                    int y=x-ans.begin();
                    ans[y]=index;
                }else{
                    ans.push_back(index);
                }
            }
        }
    return n-ans.size();
    }
};
