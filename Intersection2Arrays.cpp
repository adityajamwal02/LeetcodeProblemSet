class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        unordered_map<int,int> mp;
        vector<int> v;
        for(auto x: nums1)
            mp[x]++;
        for(auto x: nums2)
        {
            if(mp[x]>0)
                v.emplace_back(x);
                mp[x]--;
        }
        return v;
    }
};
