/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
*/

/// Better Solution

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashset;
        for(int num: nums){
            hashset.insert(num);
        }
        int longest=0;
        for(int num: nums){
            if(!hashset.count(num-1)){
                int currnum=num;
                int currstreak=1;
                while(hashset.count(currnum+1)){
                    currnum+=1;
                    currstreak+=1;
                }
                longest=max(longest,currstreak);
            }
        }
    return longest;
    }
};


/// Optimal solution

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp,vis;
        for(auto num:nums)
            mp[num]=1;
        int ans=0,cnt;

        for(auto num:nums)
        {
            cnt=0;
            if(vis[num]==0&&mp.find(num-1)==mp.end())
                while(mp.find(num)!=mp.end())
                    cnt++,vis[num]=1,num++;
            ans=max(ans,cnt);
        }
        return ans;
    }
};
