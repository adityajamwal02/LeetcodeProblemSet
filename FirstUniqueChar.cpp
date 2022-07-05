class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<char, int> mp;
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;

        for(int i=0;i<s.length();i++)
            if(mp[s[i]]==1) return i;

    return -1;
    }
};
