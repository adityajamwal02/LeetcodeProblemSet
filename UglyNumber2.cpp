/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.

Example 1:
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:
Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
*/

/// Set Solution O(n*logn)
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        long long ans=0;
        s.insert(1);
        while(n--){
            auto element=*s.begin();
            ans=element;
            s.insert(element*2);
            s.insert(element*3);
            s.insert(element*5);
            s.erase(element);
        }
    return ans;
    }
};

/// DP Solution O(n)

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int p1=0, p2=0, p3=0;
        for(int i=1; i<n; i++){
            int twoMultiple=dp[p1]*2;
            int threeMultiple=dp[p2]*3;
            int fiveMultiple=dp[p3]*5;
            dp[i]=min(twoMultiple, min(threeMultiple, fiveMultiple));
            //If else isliye nhi likhe hai kyunki agr do barabar hua to dono ko increment krna pdega.
            if(dp[i]==twoMultiple){
                p1++;
            }
            if(dp[i]==threeMultiple){
                p2++;
            }
            if(dp[i]==fiveMultiple){
                p3++;
            }
        }
        return dp[n-1];
    }
};
