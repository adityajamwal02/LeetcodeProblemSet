class Solution {
public:
    bool canConstruct(string ran, string mag) {
        unordered_map<char, int> mp;
        for(int i=0;i<mag.size();i++)
            mp[mag[i]]++;
        for(int i=0;i<ran.size();i++)
        {
            if(mp[ran[i]]>0)
                mp[ran[i]]--;
            else
                return false;
        }
        return true;
    }
};
