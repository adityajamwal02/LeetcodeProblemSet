class Solution {
public:
    bool isPowerOfTwo(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        if(n<0)
            return false;

        return (n && !(n&n-1));
    }
};
