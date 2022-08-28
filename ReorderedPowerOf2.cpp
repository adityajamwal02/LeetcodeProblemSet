/*
You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
Return true if and only if we can do this so that the resulting number is a power of two.
*/

class Solution {
public:
    string sorted(int n){
        string s=to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string str=sorted(n);
        for(int i=0;i<32;i++){
            if(str==sorted(1<<i))
                return true;
        }
    return false;
    }
};
