class Solution {
public:

    int gcd(int p,int q){
        while(q){
            p=p%q;
            swap(p,q);
        }
        return p;
    }
    int mirrorReflection(int p, int q) {
        int lcm=p*q/gcd(p,q);
        int a=lcm/p;
        int b=lcm/q;
        return (a%2==0) ? 0 : (b%2==0 ? 2 : 1);
    }
};
