class Solution {
public:
    int reverse(int x) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans=0;

        while(x != 0)
        {
            int num=x%10;

            if(ans>INT_MAX/10 or ans<INT_MIN/10)
                return  0;

            ans=(ans*10)+num;
            x/=10;
        }
    return ans;
   }
};
