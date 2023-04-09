/*
You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.
Return the array arr.

Example 1:
Input: nums = [1,3,1,1,2]
Output: [5,0,3,4,0]
Explanation:
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5.
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3.
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4.
When i = 4, arr[4] = 0 because there is no other index with value 2.

Example 2:
Input: nums = [0,5,3]
Output: [0,0,0]
Explanation: Since each element in nums is distinct, arr[i] = 0 for all i.
*/


/// Time limit exceeded (better brute force)

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long> result;
        unordered_map<int, vector<long long>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                vector<long long> temp=mp[nums[i]];
                if(temp.size()==1){
                    result.push_back(0);
                }else{
                    long long curr=0;
                    for(int j=0;j<temp.size();j++){
                        if(temp[j]!=i){
                            curr=curr+abs(i-temp[j]);
                        }
                    }
                result.push_back(curr);
                }
            }
        }
    return result;
    }
};


/// Map + Prefix Sum


class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long> result;
        unordered_map<int, vector<long long>> mp;
        unordered_map<int, vector<int>> min;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            if(!mp.count(curr)) mp[curr].push_back(0);
            mp[curr].push_back(mp[curr].back()+(long long)i+1);
            min[curr].push_back(i);
        }
        for(int i=0;i<n;i++){
            int index=lower_bound(min[nums[i]].begin(),min[nums[i]].end(),i+1)-min[nums[i]].begin();
            long long left=index, right=min[nums[i]].size()-index;
            result.push_back(left*(i+1LL)-mp[nums[i]][left-1]+mp[nums[i]].back()-mp[nums[i]][left]-(right+1LL)*(i+1LL));
        }
    return result;
    }
};
