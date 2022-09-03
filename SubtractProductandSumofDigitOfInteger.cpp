class Solution {
public:
    int subtractProductAndSum(int n) {
        int product=1;
        int sum=0;
        while(n){
            int num=n%10;
            sum+=num;
            product*=num;
            n=n/10;
        }
    return (product-sum);
    }
};
