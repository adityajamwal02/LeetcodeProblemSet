


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<n;i++){
            string r=haystack.substr(i,m);
            if(r==needle)
                return i;
        }
    return -1;
    }
};
