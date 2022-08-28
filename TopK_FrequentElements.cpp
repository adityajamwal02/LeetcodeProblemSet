class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> ans;
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto x: mp){
            ans.push_back({x.second, x.first});
        }
        sort(ans.rbegin(),ans.rend());
        vector<int> output(k);
        for(int i=0;i<k;i++){
            output[i]=ans[i].second;
        }
    return output;
    }
}
